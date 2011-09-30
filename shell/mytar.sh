#!/bin/bash
echo $#
echo $0
USAGE="Usage: `basename $0` [-c|-t] [file|directory]"
case $0 in
	*listtar) TARGS="-tvf $1" ;;
	*maketar)  TARGS="-cvf $1.tar $1" ;;
	*) echo "$USAGE"
	exit 0
	;;
esac
tar $TARGS
