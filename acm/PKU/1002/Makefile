#(c) CETC 2007
ROOTDIR=.
CC=gcc

LOCAL_INSTALL=../install/
LOCAL_INCLUDE=./include
LIB_PATH=

LIBS=

INCLUDE=-I$(LOCAL_INSTALL)/include  -I$(LOCAL_INCLUDE)
CFLAGS = -g -O2 -DLINUX -Wall -pipe #`pkg-config --cflags --libs glib-2.0 gthread-2.0`

OBJ_CLIENT = $(ROOTDIR)/*.o

default:all

%.o:%.c
	echo compiling $@
	$(CC) $(WFLAGS) $(CFLAGS) $(IFLAGS) -c $<

all:test

test: $(OBJ_CLIENT)
	$(CC) -o test $(OBJ_CLIENT) $(LIB_PATH) $(LIBS) $(CFLAGS) $(IFLAGS)

PHONY: clean
clean:
	rm *.o -rf
	rm test -f
