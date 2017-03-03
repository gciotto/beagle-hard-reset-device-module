#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>

#include <linux/gpio.h>

#define GPIO_ID 30 // P9.11

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gustavo Ciotto Pinton");
MODULE_DESCRIPTION("Hard reset kernel device module.");
MODULE_VERSION("0.1");

static int __init beagle_hard_reset_init(void) {

	if (!gpio_is_valid(GPIO_ID)){
		printk(KERN_INFO "gpio_is_valid() failed!\n");
		return -ENODEV;
	}

	if (gpio_request(GPIO_ID, "sysfs")) {
		printk(KERN_INFO "gpio_request() failed!\n");
		return -ENODEV;
	}

	gpio_direction_output(GPIO_ID, 0);
	gpio_set_value(GPIO_ID, 0);

	return 0;
}

static void __exit beagle_hard_reset_exit(void) {

	gpio_free(GPIO_ID);
}

module_init(beagle_hard_reset_init);
module_exit(beagle_hard_reset_exit);
