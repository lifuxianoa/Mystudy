#!/bin/sh
date; who am i;

band[0]=derri
band[1]=terry
band[2]=mike
band[3]=gene

echo ${band[0]}
echo ${band[1]}
echo ${band[2]}
echo ${band[3]}

x=0
while [ $x -lt 10 ]
do
#	echo $x
#	x=`echo "$x + 1" | bc`
	y="$x"
	while [ $y -ge 0 ]
	do
		echo "$y \c"
		y=`echo "$y - 1" | bc`
	done
	x=`echo "$x + 1" | bc`
done

RESPONSE=
while [ -z $RESPONSE ] ;
do
	echo "Enter the name of the directory: "
	read RESPONSE
	if [ ! -d "$RESPONSE" ] ; then
		echo "ERROR: Please enter a directory pathname."
		RESPONSE=
	fi
done
