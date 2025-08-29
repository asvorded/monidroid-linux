#include <linux/module.h>

MODULE_LICENSE("");
MODULE_AUTHOR("asvorded");
MODULE_DESCRIPTION("Monidroid kernel module");
MODULE_VERSION("0.0");

int md_main(void);
void md_exit(void);

int __init md_main(void) {
    pr_info("Monidroid kernel module init!");
    return 0;
}

void __exit md_exit(void) {
    pr_info("Monidroid kernel module exit!");
}

module_init(md_main)
module_exit(md_exit)
