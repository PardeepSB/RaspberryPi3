#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pardeep");
MODULE_DESCRIPTION("Register a device num and implement callback functions");

/* Initialize Macros */

#define MYMAJOR 90	// Unused device number determiend from 'cat /proc/devices/'

/**
 * @brief This function is called when the device file is opened
 */
static int driver_open(struct inode *device_file, struct file *instance){
	printk("dev_num - open was called!\n");
	return 0;
}

/**
 * @brief This function is called when the device file is close
 */
static int driver_close(struct inode *device_file, struct file *instance){
	printk("dev_num - close was called!\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

/**
 * @brief This function is called when the module is loaded into the kernel
 */
static int __init ModuleInit(void) {
	int retval;
	printk("Hello Kernel!\n");
	// register device num
	retval = register_chrdev(MYMAJOR, "my_dev_num", &fops);
	if(retval == 0) {
		printk("dev_num - registered Device number Major: %d, Minor: %d\n", MYMAJOR, 0);
	}
	else if(retval > 0) {
		printk("dev_num - registered Device number Major: %d, Minor: %d\n", retval>>20, retval&0xfffff);
	}
	else {
		printk("Could not register device number!\n");
		return -1;
	}
	return 0;
}

/**
 * @brief This function is called when the module is removed from the kernel
 */
static void __exit ModuleExit(void) {
	unregister_chrdev(MYMAJOR, "my_dev_num");
	printk("Goodbye, Kernel\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);

