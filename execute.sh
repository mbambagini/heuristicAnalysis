#! /bin/bash


#### PARAMETERS
#CSAs="0 1 2 3 4 5 6 7 8 9"
CSAs="1 3 5"
TSAs="0 1 2 3"


#### ARGUMENT
if [ $# -lt 2 ];
then
	echo "The parameters are missing"
	echo "$0 <software directory> <hardware file>"
	exit
fi


#### COMPILING
#make 


#### EXECUTING
directories=`ls $1/` > /dev/null

touch "$1/conf_alg.sh"
echo "#! /bin/sh" > "$1/conf_alg.sh"
echo "CSA=\"$CSAs\"" >> "$1/conf_alg.sh"
echo "TSA=\"$TSAs\"" >> "$1/conf_alg.sh"
chmod +x "$1/conf_alg.sh"

MAX_THREADS=`nproc`
MAX_THREADS=$(($MAX_THREADS*3))

source "$1/conf.sh"

resultFile="$1/results.bin"

echo "Heuristics"
NUM_THREADS=0
for n in `seq $minN $stepN $maxN`; do
	u=$minU
	while [ $(echo "$u <= $maxU"|bc) -eq 1 ]; do
		for i in `seq 1 $iters`; do
			directory="$1/n_"$n"-u_"$u"-i_"$i
			echo $directory
			for CSA in $CSAs; do
				for TSA in $TSAs; do
					./algorithm/alg --CSA $CSA --TSA $TSA --hardwareFile=$2 \
									--softwareFile=$directory/sw.bin \
									--dstFolder $directory &
					NUM_THREADS=$(($NUM_THREADS+1))
					if [ $NUM_THREADS -eq $MAX_THREADS ]; then
						wait
						NUM_THREADS=0
					fi
				done
			done
		done
		u=`expr "$u+$stepU" | bc`;
	done
done

wait

echo "Simulations"
NUM_THREADS=0
for n in `seq $minN $stepN $maxN`; do
	u=$minU
	while [ $(echo "$u <= $maxU"|bc) -eq 1 ]; do
		for i in `seq 1 $iters`; do
			directory="$1/n_"$n"-u_"$u"-i_"$i
			echo $directory
			for CSA in $CSAs; do
				for TSA in $TSAs; do
					files=`ls $directory/$CSA-$TSA-*.bin` > /dev/null
					for file in $files; do
						./simulator/sim --simFile=$file &
						NUM_THREADS=$(($NUM_THREADS+1))
						if [ $NUM_THREADS -eq $MAX_THREADS ]; then
							wait
							NUM_THREADS=0
						fi
					done
				done
			done
		done
		u=`expr "$u+$stepU" | bc`;
	done
done

wait

echo "Collecting data"
for n in `seq $minN $stepN $maxN`; do
	u=$minU
	while [ $(echo "$u <= $maxU"|bc) -eq 1 ]; do
		for i in `seq 1 $iters`; do
			directory="$1/n_"$n"-u_"$u"-i_"$i
			echo $directory
			for CSA in $CSAs; do
				for TSA in $TSAs; do
					files=`ls $directory/$CSA-$TSA-*.bin` > /dev/null
					core=1
					str=""
					for file in $files; do
						./simulator/viewer --simFile=$file > $file.txt
						str="$str--simCore$core=$file "
						core=`expr "$core+1" | bc`;
					done
					./collector/collector	--TSA $TSA --CSA $CSA \
											--platformFile=$2 $str \
											--resultsFile=$resultFile --U $u
				done
			done
		done
		u=`expr "$u+$stepU" | bc`;
	done
done
./collector/viewer --resultsFile=$resultFile > $resultFile.txt



echo "Printing"
unfeas="$1/unfeasible.res"
echo "" > $unfeas
cp ./printer/power.gpl ./$1
for CSA in $CSAs; do
	for TSA in $TSAs; do
		./printer/power --TSA $TSA --CSA $CSA --resultsFile=$resultFile > "$1/$TSA$CSA.res"
		echo "   \"$TSA$CSA.res\" using 1:2 with lines lw 6 title \"$TSA$CSA\",\\" >> ./$1/power.gpl
		./printer/unfeasible --TSA $TSA --CSA $CSA --resultsFile=$resultFile >> $unfeas
	done
done
echo "    f(x)"  >> ./$1/power.gpl
cd $1
gnuplot power.gpl
cd ..

