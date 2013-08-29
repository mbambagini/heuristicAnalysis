#! /bin/bash


#### PARAMETERS
#Period
maxBound=500
minBound=100
#Number of resources
numRes=1
#Number of tasks
minN=10
stepN=10
maxN=10
#Utilization
minU=2.0
stepU=0.25
maxU=3.0
#Instances for each problem configuration
iters=2


#### ARGUMENT
if [ $# -lt 1 ];
then
	echo "The parameter is missing"
	echo "$0 <directory>"
	exit
fi

#### DIRECTORY
if [ -d "$1" ]; then
	rm -r $1
fi
mkdir $1

touch "$1/conf.sh"
echo "#! /bin/sh" > "$1/conf.sh"
echo "minBound=$minBound" >> "$1/conf.sh"
echo "maxBound=$maxBound" >> "$1/conf.sh"
echo "numRes=$numRes" >> "$1/conf.sh"
echo "minN=$minN" >> "$1/conf.sh"
echo "stepN=$stepN" >> "$1/conf.sh"
echo "maxN=$maxN" >> "$1/conf.sh"
echo "minU=$minU" >> "$1/conf.sh"
echo "stepU=$stepU" >> "$1/conf.sh"
echo "maxU=$maxU" >> "$1/conf.sh"
echo "iters=$iters" >> "$1/conf.sh"
chmod +x "$1/conf.sh"


#### COMPILING
#make

#### EXECUTING
for n in `seq $minN $stepN $maxN`; do
	u=$minU
	while [ $(echo "$u <= $maxU"|bc) -eq 1 ]; do
		for i in `seq 1 $iters`; do
			directory="$1/n_"$n"-u_"$u"-i_"$i
			mkdir $directory
			./generator/software	--binaryFile=$directory/sw.bin \
									--maxBound $maxBound \
									--minBound $minBound \
									--alpha $alpha
									--numRes $numRes --n $n --u $u \
									--seed $RANDOM
			./generator/software_viewer	\
								 --srcFile=$directory/sw.bin > $directory/sw.txt
		done
		u=`expr "$u+$stepU" | bc`;
	done
done

