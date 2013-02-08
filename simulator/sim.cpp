/*! \file sim.cpp
 *
 * This file contains a simple implementation of a Fixed-Priority simulator 
 * which accounts the time spent in active, idle, switching and sleep states.
 * The break-even time is taken into account.
 * During idle time, the energy saving algorithm switch the processor off if
 * and only if the time until next task arrival is longer than the BET.
 * Altohough it would be possible to further procastine task execution, such
 * feature is not considered here in order to make the simulation as simple as
 * the implementation of the energy saving algorithm on a real system.
 * The simulation concerns only single-core platforms.
 */


#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <limits>
#include <math.h>

#include <gflags/gflags.h>

#include <simulations.pb.h>


using namespace std;
using namespace Simulations;


/*!
 * input file with the problem specifications (tasks, bet...)
 */
DEFINE_string(simFile, "", "Simulation file");


/*!
 * this structure is in charge of collction information related to the time
 * spent
 */
struct t_timeAccounter {
	double active;
	double idle;
	double switching;
	double sleep;
	double off;
	int nOfPreemption;
	int nOfAlgCalls;
	int nOfIdle;
	unsigned long int idleTime;
	t_timeAccounter () {
		active = switching = sleep = idle = off = 0.0;
		nOfPreemption = nOfAlgCalls = idleTime = nOfIdle = 0;
	}
};


/*!
 * Notify a fatal error and exit
 */
void fatal_error (string msg);

/*!
 * Notify a real-time error (only the first time) without exiting
 */
void realtime_error (string msg);


/*!
 * simulation function
 */
t_timeAccounter schedule	(	int eoh,				//horizon analysis
								int n,					//task number
								const vector<int>& C,	//computational times
								const vector<int>& T,	//periods
								const vector<int>& D,	//deadlines
								//const vector<int>& tolerances,
								int bet					//break-even time
							);


int main (int argc, char *argv[])
{
	//check inputs
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	google::ParseCommandLineFlags(&argc, &argv, false);
	Simulations::Simulation sim;
	if (FLAGS_simFile=="")
		fatal_error("specify a simulation file");
	fstream input(FLAGS_simFile.c_str(), ios::in | ios::binary);
	if (!sim.ParseFromIstream(&input))
		fatal_error("Failed to parse "+FLAGS_simFile);
	input.close();
	t_timeAccounter t;

#ifdef DEBUG
	cout<<"U: "<<sim.utilization()<<", core: "<<sim.core()<<", feasible: "<<
														   sim.feasible()<<endl;
#endif

	//simulation
	if (sim.feasible() && sim.tasks_size()>0) {
		vector<int> wcets(sim.tasks_size());
		vector<int> periods(sim.tasks_size());
		vector<int> deadlines(sim.tasks_size());
//		vector<int> tolerances(sim.tasks_size());
		for (int i=0; i<sim.tasks_size(); i++) {
			wcets[i] = sim.tasks(i).wcet();
			periods[i] = sim.tasks(i).period();
			deadlines[i] = sim.tasks(i).deadline();
//			double tmp = 1.0;
//			for (int k=0; k<=i; k++)
//				tmp -= (double)wcets[k]/periods[k];
//			tolerances[i] = trunc(tmp*periods[i]);
#ifdef DEBUG
			cout<<"Task "<<i<<": ("<<wcets[i]<<", "<<periods[i];
			cout<<", "<<deadlines[i]<<")"<<endl;//","<<tolerances[i]<<")"<<endl;
#endif
		}
			t = schedule (numeric_limits<int>::max(), sim.tasks_size(), wcets,
//								 periods, deadlines, tolerances, sim.bet());
												 periods, deadlines, sim.bet());
	} else
		t.off = 1.0;

	//result serialization
	Simulations::Result* res = sim.mutable_res();
	res->set_off(t.off>0.0);
	res->set_activetime(t.active);
	res->set_sleeptime(t.sleep);
	res->set_switchingtime(t.switching);
	res->set_idletime(t.idle);
	res->set_nofpreemptions(t.nOfPreemption);
	res->set_nofinvocations(t.nOfAlgCalls);
	res->set_nofsleeps(t.nOfIdle);
	fstream output(FLAGS_simFile.c_str(), ios::out|ios::trunc|ios::binary);
	if (!sim.SerializeToOstream(&output))
		return false;
	output.close();
#ifdef DEBUG
	cout<<"OFF="<<t.off<<", ACTIVE: "<<t.active<<", SLEEP: "<<t.sleep;
	cout<<", SWITCHING: "<<t.switching<<", IDLE: "<<t.idle<<endl;
#endif

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}


t_timeAccounter schedule (int eoh, int n, const vector<int>& C,
									 const vector<int>& T, const vector<int>& D,
//										 		  const vector<int>& tolerances,
																		int bet)
{
	t_timeAccounter accounter;
	int currentTask = -1, prevTask = -1;
	//remaining computation, absolute deadline, release time, next release time
	vector<int> c(n), d(n), r(n), r_next(n); 
	unsigned long int now = 0, prev = 0, wakeup = 0, sleepTime = 0;
	for (int i=0; i<n; i++) {
		c[i] = r[i] = r_next[i] = 0;
		d[i] = -1;
	}
	enum t_state {ACTIVE, IDLE, SLEEP};
	t_state state = IDLE;

	//main loop...
	while (1) {
		int nextAct = numeric_limits<int>::max();
		int nextEnd = numeric_limits<int>::max();
		prevTask = -1;

		//in case the cpu is sleeping, check whether it must be waken up
		if (state==SLEEP) {
			if (currentTask!=-1)
				realtime_error("System asleep, but task in execution");
			if (wakeup>0 && wakeup==now) {
				state = IDLE;
				if ((now-sleepTime)>=bet) {
					accounter.sleep += now-sleepTime-bet;
					accounter.switching += bet;
				} else
					accounter.idle += now-sleepTime;
				wakeup = 0;
#ifdef DEBUG_TRACE
				cout<<"wake up at "<<now<<endl;
#endif
			}
		}

		//if the cpu is executing a job, either put such job in ready queue
		//(if it still has to execute) or terminate it (if it has termited its
		//execution).
		//This is a logical operation to make calculus simpler as, if the task 
		//will be reasumed immediatilly, the moving would never happen in
		//reality
		if (state==ACTIVE) {
			if (currentTask==-1)
				realtime_error("System active, but no task in execution");
			c[currentTask] -= now - prev;
			prevTask = currentTask;
			accounter.active += now - prev;
			if (c[currentTask]<0)
				realtime_error("Wrong remaning C");
			state = IDLE;
			//JOB ENDING
			if (c[currentTask]==0) { //it has just terminated its execution
#ifdef DEBUG_TRACE
				cout<<"task "<<currentTask<<" ends at "<<now<<endl;
#endif
				prevTask = currentTask = -1;
			}
		}

		//active all the tasks that have just arrived
		for (int i=0; i<n; i++) {
			if (r_next[i]==now) {
				if (c[i]>0)
					realtime_error("Deadline miss");
				c[i] = C[i];
				r[i] = now;
				r_next[i] = now+T[i];//(floor((double)now/T[i])+1)*T[i];
				d[i] = r[i] + D[i];
/******************************************************************************
//				if (state==SLEEP)
//					wakeup = wakeup>0 ? min(wakeup, now+tolerances[i]) :
//															  now+tolerances[i];
 ******************************************************************************/
#ifdef DEBUG_TRACE
				cout<<"task "<<i<<" arrives at "<<now<<endl;
#endif
			}
			nextAct = min(nextAct, r_next[i]);
		}

		//execute the task with highest priority in ready queue, if any
		if (state!=SLEEP) {
			int minD = numeric_limits<int>::max();
			for (int i=0; i<n; i++)
				if (c[i]>0 && minD>d[i]) {
					minD = d[i];
					currentTask = i;
					nextEnd = now+c[currentTask];
					state = ACTIVE;
				}
			if (prevTask!=-1 && currentTask!=prevTask)
				accounter.nOfPreemption++;
#ifdef DEBUG_TRACE
			if (currentTask!=-1 && prevTask!=currentTask)
				cout<<"task "<<currentTask<<" starts running at "<<now<<endl;
#endif
		}

		//in case the ready queue is empty, no task waiting to be executed,
		//switch the system off until next arrival, if possible
		//actually, for the sake of implementation simplicity, the control
		//(turning the system off or remaining in idle mode) is done at the
		//wake up. Of course, on a real system it must be done now, before 
		//putting the system into a low power state
		if (currentTask==-1 && state!=SLEEP) {
			accounter.nOfAlgCalls++;
			accounter.nOfIdle++;
			state = SLEEP;
			sleepTime = now;
/******************************************************************************
//			wakeup = 0;
 ******************************************************************************/
			wakeup = nextAct;
#ifdef DEBUG_TRACE
			cout<<"sleep at "<<now<<endl;
#endif
		}

		//find next scheduling event and move the analysis to it
		if (nextAct==numeric_limits<int>::max() &&
										  nextEnd==numeric_limits<int>::max())
			fatal_error("Error: no events?!");
		prev = now;
		now = min(nextAct, nextEnd);
		if (state==SLEEP && wakeup>0)
			now = min(now, wakeup);
		if (now>eoh)
			break;
	}
	accounter.off = 0.0;
	accounter.active /= eoh;
	accounter.idle /= eoh;
	accounter.sleep /= eoh;
	accounter.switching /= eoh;
	return accounter;
}


void realtime_error (string msg)
{
	static bool any = false;
	if (!any) {
		cerr<<"RT error: "<<msg<<endl;
		any = true;
	}
}


void fatal_error (string msg)
{
	cerr<<"Error: "<<msg<<endl;
	exit(0);
}

