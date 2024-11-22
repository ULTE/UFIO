#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_DESCRIPTION("ufio_module");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");

extern int ufio_dummy_init(void);
extern void ufio_dummy_exit(void);

static int dummy_init(void)
{
	return ufio_dummy_init();
}

static void dummy_exit(void)
{
	ufio_dummy_exit();
}

module_init(dummy_init);
module_exit(dummy_exit);