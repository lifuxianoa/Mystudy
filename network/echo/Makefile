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


all: echo_s echo_c

%.o:%.c
	echo compiling $@
	$(CC) $(WFLAGS) $(CFLAGS) $(IFLAGS) -c -o $@ $<

echo_s: echo_s.o unp.o
	$(CC) -o echo_s echo_s.o unp.o $(CFLAGS) $(DEBUG_FLAG) $(LIBSLINK)

echo_c: echo_c.o unp.o
	$(CC) -o echo_c echo_c.o unp.o $(CFLAGS) $(DEBUG_FLAG) $(LIBSLINK)

clean:
	/bin/rm -f *.o
	/bin/rm -f echo_s
	/bin/rm -f echo_c
