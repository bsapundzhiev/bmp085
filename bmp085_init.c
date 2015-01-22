/*
 * Copyright (c) 2015  Borislav Sapundzhiev
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/i2c.h>

/* module for explicit detect i2c device by bus id */

#define	I2C_BUS_MAX	4

static struct i2c_board_info bmp085_i2c_info[] = {
		
	{I2C_BOARD_INFO("bmp085", 0x77),}
};

static int __init bmp085_i2c_init(void)
{
	int nr;
	for(nr =0; nr < I2C_BUS_MAX; nr++) {
	
		struct i2c_adapter * adap = i2c_get_adapter(nr);
		if(adap) {
			//i2c_new_device(adap, bmp085_i2c_info);
			i2c_new_probed_device(adap, bmp085_i2c_info, 
						I2C_ADDRS(0x77), NULL);
		}
	}

	return 0;
}

static void __exit bmp085_i2c_exit(void)
{
	printk(KERN_ALERT "[%s] Exit\n", "bmp085_init");
}

module_init(bmp085_i2c_init);
module_exit(bmp085_i2c_exit);

MODULE_AUTHOR("Borislav Sapundzhiev <BSapundzhiev@gmail.com>");
MODULE_DESCRIPTION("bmp085/18x init");
MODULE_LICENSE("GPL");
