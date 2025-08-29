obj-m := monidroid.o
monidroid-y := main.o

default:
	make -C /lib/modules/`uname -r`/build M=$(PWD)

clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean
