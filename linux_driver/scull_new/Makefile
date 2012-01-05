#Makefile 2.6

#Comment/uncomment the following line to disable/enable debugging
DEBUG = y

#Add your debugging flag (or not) to CFLAGS
ifeq ($(DEBUG),y)
    DEBFLAGS = -O -g -DSCULL_DEBUG #'-0' is needed to expand inlines
else
    DEBFLAGS = -O2
endif

#CFLAGS += $(DEBFLAGS)

ifneq ($(KERNELRELEASE),)
	#kbuild syntax dependency relationship of files and target modules are listed here.
	mymodule-objs:=scull.o
	obj-m:=scull.o
else
	PWD:=$(shell pwd)
	KVER?=$(shell uname -r)
	KDIR:=/lib/modules/$(KVER)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

endif

