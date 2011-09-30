# Copyright (c) 2009, 30KT 
# All rights reserved.
# authors:   wupeng<wupeng@30kt.com>
# date:      2009-07-07

MAIN = all

CC = gcc
#CC = /opt/crosstool/gcc-3.4.5-glibc-2.3.6/arm-davinci-linux/bin/arm-davinci-linux-gcc

INCDIRS = -I 
LIBDIRS = -L 
CFLAGS = -Wall -O2 -g -DMEMWATCH -DMW_STDIO $(INCDIRS) $(LIBDIRS)

LIBSLINK =  

DEBUG_FLAG =
.SUFFIXES= .o .c


all: sockopt

%.o:%.c
	echo compiling $@
	$(CC) $(WFLAGS) $(CFLAGS) $(IFLAGS) -c -o $@ $<

sockopt: sockopt.o unp.o
	$(CC) -o $@ $< $(CFLAGS) $(DEBUG_FLAG) $(LIBSLINK)

clean:
	/bin/rm -f *.o
	/bin/rm -f sockopt
