
obj-m := globalfifo.o
#obj-m := globalfifomod.o
#globalfifomod-objs := globalfifo.o

KDIR := /lib/modules/`uname -r`/build
CURRDIR := $(shell pwd)


default:
	make -C $(KDIR) M=$(CURRDIR) modules

clean:
	make -C $(KDIR) M=$(CURRDIR) clean
	#rm -rf *.o .*.cmd  *.ko *.mod.c .tmp_versions
