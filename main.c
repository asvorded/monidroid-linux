#include "main.h"

#include <linux/module.h>

#include <drm/drm.h>
#include <drm/drm_drv.h>
#include <drm/drm_device.h>
#include <drm/drm_utils.h>
#include <drm/drm_util.h>
#include <drm/drm_module.h>
#include <drm/drm_ioctl.h>
#include <drm/drm_gem.h>

#include "monidroid.h"
#include "driver.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("asvorded");
MODULE_DESCRIPTION("Monidroid indirect display driver");
MODULE_VERSION("0.1");

DEFINE_DRM_GEM_FOPS(md_fops);

static const struct drm_ioctl_desc md_ioctls[] = {
    DRM_IOCTL_DEF_DRV(IDD_MONITOR_CONNECT, md_ioctl_connect_monitor, 0),
    DRM_IOCTL_DEF_DRV(IDD_MONITOR_DISCONNECT, md_ioctl_disconnect_monitor, 0),
    DRM_IOCTL_DEF_DRV(IDD_REQUEST_FRAME, md_ioctl_frame_request, 0)
};

struct drm_driver md_driver = {
    .open = md_cb_open,
    .postclose = md_cb_postclose,
    // .gem_create_object = md_cb_gem_create_object,
    .major = MD_MAJOR_VERSION,
    .minor = MD_MINOR_VERSION,
    .patchlevel = MD_PATCHLEVEL_VERSION,
    .name = MD_DRIVER_NAME,
    .desc = MD_DRIVER_DESC,
    .driver_features = DRIVER_GEM,
    .fops = &md_fops,
    .ioctls = md_ioctls,
    .num_ioctls = ARRAY_SIZE(md_ioctls)
};

static struct device *root_device = NULL;
static struct drm_device* md_device = NULL;

static int __init md_init(void) {
    pr_info("Monidroid driver loaded");
    
    root_device = root_device_register(MD_DRIVER_NAME);

    md_device = drm_dev_alloc(&md_driver, root_device);
    if (IS_ERR_OR_NULL(md_device)) {
        pr_err("Error while creating device!");
        return PTR_ERR_OR_ZERO(md_device);
    }

    int code = drm_dev_register(md_device, 0);
    if (code) {
        drm_dev_put(md_device);
        pr_err("Error while registering device!");
        return code;
    }
    
    return 0;
}

static void __exit md_exit(void) {
    root_device_unregister(root_device);

    drm_dev_unregister(md_device);
    drm_dev_put(md_device);

    pr_info("Monidroid driver unloaded");
}

module_init(md_init);
module_exit(md_exit);
