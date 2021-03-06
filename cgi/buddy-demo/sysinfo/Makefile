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
LDFLAGS =

CFLAGS += -I$(PREFIX)/usr/local/include/
CFLAGS += -I../include/
LDFLAGS += -L$(PREFIX)/usr/local/lib

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

TARGET = sysinfo
ifeq ($(TARGET),)
	TARGET = $(notdir $(PWD))
endif

LIB = lib$(TARGET).a lib$(TARGET).so
DEPEND = $(notdir $(wildcard .depend))

all:.depend lib#$(TARGET)

.depend: $(SRC)
	$(CC) $(CFLAGS) -w -MM $^ > $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

lib$(TARGET).a: lib$(TARGET).a($(OBJ))
	$(RANLIB) $@

lib$(TARGET).so: $(OBJ)
	$(CC) -shared -fPIC -o $@ $<

lib: $(LIB)

ifneq ($(DEPEND),)
	include .depend
endif

clean:
	$(RM) $(TARGET) $(OBJ) .depend $(LIB)

