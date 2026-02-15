#include <linux/module.h>

int __init md_main(void) {
    pr_info("Monidroid kernel module init!");
    return 0;
}

void __exit md_exit(void) {
    pr_info("Monidroid kernel module exit!");
}

module_init(md_main)
module_exit(md_exit)

MODULE_LICENSE("");
MODULE_AUTHOR("asvorded");
MODULE_DESCRIPTION("Monidroid kernel module");
MODULE_VERSION("0.0");
