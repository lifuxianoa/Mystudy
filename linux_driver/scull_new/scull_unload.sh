#!/bin/sh
module="scull"
device="scull"

#invoke rmsmod with all arguments we got
/sbin/rmmod -f $module $* || exit 1

#remove stale nodes
rm -f /dev/${device}[0-3]
