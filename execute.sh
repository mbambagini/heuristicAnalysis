#! /bin/bash

#### PARAMETERS
N_MIN=150
N_STEP=150
N_MAX=150

U_MIN=5.0
U_STEP=2.5
U_MAX=40.0

ITERS=100

CSA="0 1"

#### ARGUMENT
if [ $# -lt 2 ];
then
	echo "The parameters are missing"
	echo "$0 <softwre directory> <hardware file>"
	exit
fi

#### COMPILING
#make 

#### EXECUTING
mkdir $1

########### GENERATE SOFTWARE
echo "Software generation"
mkdir $1/sw
for n in `seq $N_MIN $N_STEP $N_MAX`; do
	u=$U_MIN
	while [ $(echo "$u <= $U_MAX"|bc) -eq 1 ]; do
		if [ $(echo "$n <= $u"|bc) -eq 1 ]; then
			break;
		fi
		for i in `seq 1 $ITERS`; do
			directory="$1/sw/n_"$n"-u_"$u"-i_"$i
			mkdir $directory
			./S2-generator/software	--binaryFile=$directory/sw.bin \
									--numRes 1 --n $n --u $u \
									--seed $RANDOM
#									--maxBound $maxBound --minBound $minBound \
			./S2-generator/software_viewer	\
								 --srcFile=$directory/sw.bin > $directory/sw.txt
		done
		u=`expr "$u+$U_STEP" | bc`;
	done
done

echo "Heuristics"
for n in `seq $N_MIN $N_STEP $N_MAX`; do
	u=$U_MIN
	while [ $(echo "$u <= $U_MAX"|bc) -eq 1 ]; do
		if [ $(echo "$n <= $u"|bc) -eq 1 ]; then
			break;
		fi
		for i in `seq 1 $ITERS`; do
			directory="$1/sw/n_"$n"-u_"$u"-i_"$i
			echo $directory
			for csa in $CSA; do
				./S3-algorithm/alg	--swFile=$directory/sw.bin \
									--dstFile=$directory/$csa.bin \
									--hwFile=$2 --CSA $csa

				./S3-algorithm/viewer --srcFile=$directory/$csa.bin > \
													 $directory/$csa.txt
			done
		done
		u=`expr "$u+$U_STEP" | bc`;
	done
done

echo "Collecting data"
resultFile="$1/results.bin"
for n in `seq $N_MIN $N_STEP $N_MAX`; do
	u=$U_MIN
	while [ $(echo "$u <= $U_MAX"|bc) -eq 1 ]; do
		if [ $(echo "$n <= $u"|bc) -eq 1 ]; then
			break;
		fi
		for i in `seq 1 $ITERS`; do
			directory="$1/sw/n_"$n"-u_"$u"-i_"$i
			echo $directory
			for csa in $CSA; do
					./S4-collector/collector --binaryFile=$resultFile \
											 --hwFile=$2 \
											 --partitionFile=$directory/$csa.bin
			done
		done
		u=`expr "$u+$U_STEP" | bc`;
	done
done
./S4-collector/viewer --srcFile=$resultFile > $resultFile.txt

echo "Printing"
dirU=$1/analysis_U
rm -rf $dirU
mkdir $dirU
for n in `seq $N_MIN $N_STEP $N_MAX`; do
	cp ./S5-printer/analyze_U.gpl $dirU/power$n.gpl
	for csa in $CSA; do
		./S5-printer/power --srcFile=$resultFile \
				--u_min $U_MIN --u_step $U_STEP --u_max $U_MAX \
				--n $n --csa $csa > $dirU/$csa.$n.dat
		if [[ $n -eq $N_MAX && $csa -eq 1 ]]; then
			echo "	\"$dirU/$csa.$n.dat\" using 1:(\$2==0?1/0:\$2) with linespoints lw 9 title \"$csa no sfa\", \\" >> $dirU/power$n.gpl
			echo "	\"$dirU/$csa.$n.dat\" using 1:(\$3==0?1/0:\$3) with linespoints lw 9 title \"$csa sfa\"" >> $dirU/power$n.gpl
		else
			echo "	\"$dirU/$csa.$n.dat\" using 1:(\$2==0?1/0:\$2) with linespoints lw 9 title \"$csa no sfa\", \\" >> $dirU/power$n.gpl
			echo "	\"$dirU/$csa.$n.dat\" using 1:(\$3==0?1/0:\$3) with linespoints lw 9 title \"$csa sfa\", \\" >> $dirU/power$n.gpl
		fi
	done
	gnuplot $dirU/power$n.gpl
	mv power.eps $dirU/$n.eps
done

dirN=$1/analysis_N
rm -rf $dirN
mkdir $dirN
u=$U_MIN
while [ $(echo "$u <= $U_MAX"|bc) -eq 1 ]; do
	cp ./S5-printer/analyze_U.gpl $dirN/power$u.gpl
	u_upper_bound=$u
	u_lower_bound=`expr "$u-$U_STEP" | bc`;

	for csa in $CSA; do
		./S5-printer/powerN --srcFile=$resultFile \
				--n_min $N_MIN --n_step $N_STEP --n_max $N_MAX \
				--u_min $u_lower_bound --u_max $u_upper_bound --csa $csa > $dirN/$csa.$u.dat
		if [[ $n -eq $N_MAX && $csa -eq 1 ]]; then
			echo "	\"$dirN/$csa.$u.dat\" using 1:(\$2==0?1/0:\$2) with linespoints lw 9 title \"$csa no sfa\", \\" >> $dirN/power$u.gpl
			echo "	\"$dirN/$csa.$u.dat\" using 1:(\$3==0?1/0:\$3) with linespoints lw 9 title \"$csa sfa\"" >> $dirN/power$u.gpl
		else
			echo "	\"$dirN/$csa.$u.dat\" using 1:(\$2==0?1/0:\$2) with linespoints lw 9 title \"$csa no sfa\", \\" >> $dirN/power$u.gpl
			echo "	\"$dirN/$csa.$u.dat\" using 1:(\$3==0?1/0:\$3) with linespoints lw 9 title \"$csa sfa\", \\" >> $dirN/power$u.gpl
		fi
	done
	gnuplot $dirN/power$u.gpl
	mv power.eps $dirN/$csa.$u.eps
	u=`expr "$u+$U_STEP" | bc`;
done

dirU=$1/analysis_U_alpha
rm -rf $dirU
mkdir $dirU
for n in `seq $N_MIN $N_STEP $N_MAX`; do
	for csa in $CSA; do
		cp ./S5-printer/analyze_U.gpl $dirU/power$csa-$n.gpl
		./S5-printer/power_alpha --srcFile=$resultFile \
				--u_min $U_MIN --u_step $U_STEP --u_max $U_MAX \
				--n $n --csa $csa > $dirU/$csa.$n.dat
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$2==0?1/0:\$2) with linespoints lw 9 title \"$csa DPM\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$3==0?1/0:\$3) with linespoints lw 9 title \"$csa DVFS 0.0\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$4==0?1/0:\$4) with linespoints lw 9 title \"$csa DVFS 0.1\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$5==0?1/0:\$5) with linespoints lw 9 title \"$csa DVFS 0.2\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$6==0?1/0:\$6) with linespoints lw 9 title \"$csa DVFS 0.3\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$7==0?1/0:\$7) with linespoints lw 9 title \"$csa DVFS 0.4\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$8==0?1/0:\$8) with linespoints lw 9 title \"$csa DVFS 0.5\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$9==0?1/0:\$9) with linespoints lw 9 title \"$csa DVFS 0.6\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$10==0?1/0:\$10) with linespoints lw 9 title \"$csa DVFS 0.7\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$11==0?1/0:\$11) with linespoints lw 9 title \"$csa DVFS 0.8\", \\" >> $dirU/power$csa-$n.gpl
		echo "	\"$dirU/$csa.$n.dat\" using 1:(\$12==0?1/0:\$12) with linespoints lw 9 title \"$csa DVFS 0.9\", \\" >> $dirU/power$csa-$n.gpl
		if [[ $n -eq $N_MAX && $csa -eq 1 ]]; then
			echo "	\"$dirU/$csa.$n.dat\" using 1:(\$13==0?1/0:\$13) with linespoints lw 9 title \"$csa DVFS 1.0\"" >> $dirU/power$csa-$n.gpl
		else
			echo "	\"$dirU/$csa.$n.dat\" using 1:(\$13==0?1/0:\$13) with linespoints lw 9 title \"$csa DVFS 1.0\", \\" >> $dirU/power$csa-$n.gpl

		fi
		gnuplot $dirU/power$csa-$n.gpl
		mv power.eps $dirU/$csa-$n.eps
	done
done

