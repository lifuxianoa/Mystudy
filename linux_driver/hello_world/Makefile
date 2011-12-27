#Makefile 2.6
ifneq ($(KERNELRELEASE),)
	#kbuild syntax dependency relationship of files and target modules are listed here.
	mymodule-objs:=hello.o
	obj-m:=hello.o
else
	PWD:=$(shell pwd)
	KVER?=$(shell uname -r)
	KDIR:=/lib/modules/$(KVER)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

endif

