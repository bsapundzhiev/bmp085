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

*Config
-------
$ sudo nano /etc/modprobe.d/raspi-blacklist.conf
Uncoment the follow line
#blacklist spi-bcm2708
#blacklist i2c-bcm2708

$ sudo nano /etc/modules 
Add lines follow
bmp085
bmp085-i2c
bmp085_init

*Test:
-------
$ sudo modprobe bmp085 bmp085-i2c bmp085_init 

$ cat /sys/bus/i2c/drivers/bmp085/1-0077/temp0_input
$ cat /sys/bus/i2c/drivers/bmp085/1-0077/pressure0_input
