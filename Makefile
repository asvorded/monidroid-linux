obj-m := monidroid.o
monidroid-y := main.o driver.o

MD_DIR = $(CURDIR)
MD_BUILD_DIR = $(MD_DIR)/build

all:
	make -C /lib/modules/`uname -r`/build M=$(MD_DIR) MO=$(MD_BUILD_DIR)

install:
	make -C /lib/modules/`uname -r`/build M=$(MD_BUILD_DIR) modules_install

clean:
	make -C /lib/modules/`uname -r`/build M=$(MD_BUILD_DIR) clean
