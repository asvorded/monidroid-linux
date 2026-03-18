#include "driver.h"

int md_cb_open(struct drm_device *device, struct drm_file *file) {
    return 0;
}

void md_cb_postclose(struct drm_device *device, struct drm_file *file) {
    //
}

struct drm_gem_object* md_cb_gem_create_object(struct drm_device *dev, size_t size) {
    return NULL;
}

int md_ioctl_connect_monitor(struct drm_device *dev, void *data, struct drm_file *file) {
    return 0;
}

int md_ioctl_disconnect_monitor(struct drm_device *dev, void *data, struct drm_file *file) {
    return 0;
}

int md_ioctl_frame_request(struct drm_device *dev, void *data, struct drm_file *file) {
    return 0;
}
