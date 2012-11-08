#!/bin/bash
clear
if [ -z $2 ]; then
	g++ -o $1 $1.cpp -Wall -pedantic -lm -g -lcrypt -O2 -pipe -D MACRO
else
	g++ -o $1 $1.cpp -Wall -pedantic -lm -g -lcrypt -O2 -pipe
fi

if [ $? != 0 ]; then 
	echo '### NAO COMPILOU ###';
else 
	echo '### COMPILOU ###';
	./$1 < $1.in | tee $1.out
	#./$1 < $1.in
	if [ $? != 0 ]; then
		echo '### RUNTIME ERROR ###';
	else
		if [ ! -z $2 ]; then
			echo '### diff ###'
			diff $1.out $1.padrao;
		fi
	fi
fi

