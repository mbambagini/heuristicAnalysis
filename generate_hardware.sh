#! /bin/sh


#### ARGUMENT
if [ $# -lt 1 ];
then
	echo "The parameter is missing"
	echo "$0 <project name>"
	exit
fi


#### COMPILING
make


#### EXECUTING
./generator/hardware		--binaryFile=$1.bin
./generator/hardware_viewer	--srcFile=$1.bin > $1.txt
