#pragma once

#include <drm/drm_device.h>
#include <drm/drm_file.h>
#include <drm/drm_gem.h>
#include <drm/drm_print.h>

#include "monidroid.h"

/**
 * @brief Called when @c open() called from userspace
 */
int md_cb_open(struct drm_device *, struct drm_file *);

/**
 * @brief Called when @c close() called from userspace
 */
void md_cb_postclose(struct drm_device *, struct drm_file *);

/**
 * @brief Constructor for GEM objects
 */
struct drm_gem_object* md_cb_gem_create_object(struct drm_device *, size_t size);

int    md_ioctl_connect_monitor(struct drm_device *, void *data, struct drm_file *);
int md_ioctl_disconnect_monitor(struct drm_device *, void *data, struct drm_file *);
int      md_ioctl_frame_request(struct drm_device *, void *data, struct drm_file *);
