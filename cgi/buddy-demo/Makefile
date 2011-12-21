HOST   = #(specify host type here, such as arm-linux or arm-uclibc-linux)
CC     = gcc
RANLIB = ranlib

ifneq ($(HOST),)
	HOSTE  = $(addsuffix -,$(HOST))
	CC     = $(addprefix $(HOSTE),gcc)
	RANLIB = $(addprefix $(HOSTE),ranlib)
endif

#specify prefix here
PREFIX =

#specify your custmized compile flags here
CFLAGS  = -Wall
LDFLAGS = -lxml2 -lsysinfo

CFLAGS += -I$(PREFIX)/usr/local/include/
CFLAGS += -I$(PREFIX)/usr/include/libxml2
CFLAGS += -I./include

LDFLAGS += -L$(PREFIX)/usr/local/lib
LDFLAGS += -L$(PREFIX)/usr/lib/libxml2
LDFLAGS += -L./lib

ifeq ($(TYPE),debug)
	CFLAGS += -g3
else
	ifeq ($(TYPE), release)
	CFLAGS += -O2
else
	CFLAGS += -g -O
endif
endif

SRC = $(notdir $(wildcard *.c))
OBJ = $(patsubst %.c,%.o,$(SRC))

TARGET = main.cgi
ifeq ($(TARGET),)
	TARGET = $(notdir $(PWD))
endif

LIB = lib$(TARGET).a
DEPEND = $(notdir $(wildcard .depend))

all:.depend $(TARGET)

.depend: $(SRC)
	$(CC) $(CFLAGS) -w -MM $^ > $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(LIB):$(LIB)($(OBJ))
	$(RANLIB) $@
lib: $(LIB)

ifneq ($(DEPEND),)
	include .depend
endif

clean:
	$(RM) $(TARGET) $(OBJ) .depend $(LIB)

