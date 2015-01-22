Linux kernel driver modified to work with bmp180
------------------------------------------------
Raspberry Pi how-to
--------------------
$ make 
$ sudo make install 

$ sudo depmod -a

$ sudo nano /etc/modprobe.d/raspi-blacklist.conf
blacklist spi-bcm2708
#blacklist i2c-bcm2708

$ sudo nano /etc/modules 

bmp085
bmp085-i2c
bmp085_init

$ sudo modprobe bmp085 bmp085-i2c bmp085_init 

Test:
------
$ cat /sys/bus/i2c/drivers/bmp085/1-0077/temp0_input
$ cat /sys/bus/i2c/drivers/bmp085/1-0077/pressure0_input
