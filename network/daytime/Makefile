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


all: daytime_s daytime_c

%.o:%.c
	echo compiling $@
	$(CC) $(WFLAGS) $(CFLAGS) $(IFLAGS) -c -o $@ $<

test: network_info.o
	${CC} -o test network_info.o $(CFLAGS) ${DEBUG_FLAG} $(LIBSLINK)

cap: socket_packet.o
	$(CC) -o cap  socket_packet.o $(CFLAGS) $(DEBUG_FLAG) $(LIBSLINK)

daytime_s: daytime_s.o
	$(CC) -o daytime_s daytime_s.o $(CFLAGS) $(DEBUG_FLAG) $(LIBSLINK)

daytime_c: daytime_c.o
	$(CC) -o daytime_c daytime_c.o $(CFLAGS) $(DEBUG_FLAG) $(LIBSLINK)

clean:
	/bin/rm -f *.o
	/bin/rm -f test
	/bin/rm -f cap
	/bin/rm -f daytime_s
	/bin/rm -f daytime_c
