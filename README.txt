Linux kernel driver for bmp085 bmp180 sensor
--------------------------------------------

This is kernel driver from Linux/drivers/misc/ 
with aditional module for i2c sensor detection 

Raspberry Pi how-to
--------------------
*Build
------
$ make 
$ sudo make install 
$ sudo depmod -a

*Cross build
-------------
$ export CCPREFIX=$HOME/cross/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf- 
$ export KERNEL_SRC=$HOME/cross/linux-rpi
$ make cross

*Config
-------
$ sudo nano /etc/modprobe.d/raspi-blacklist.conf
Uncoment the following lines
#blacklist i2c-bcm2708

NOTE: on kernels above 3.16 i2c should be enabled through raspi-config -> advanced 
 
$ sudo nano /etc/modules 
Add lines as follow
bmp085
bmp085-i2c
bmp085-probe

*Test:
-------
$ sudo modprobe bmp085 bmp085-i2c bmp085-probe 

$ cat /sys/bus/i2c/drivers/bmp085/1-0077/temp0_input
$ cat /sys/bus/i2c/drivers/bmp085/1-0077/pressure0_input
