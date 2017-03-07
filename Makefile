obj-m+=beagle_gpio.o

modules:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
install: modules
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules_install
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
