
ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m   := hello.o
obj-m   += hello1.o
obj-m   += hello2.o
else
# normal makefile
# KDIR ?= /lib/modules/`uname -r`/build
KDIR ?= /home/max/gl/src/kernel/linux-4.13_arm64

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
