#pragma once

#include <drm/drm.h>

struct adapter_monitor_info;
struct frame_monitor_info;

#define DRM_IOCTL_IDD_MONITOR_CONNECT            DRM_IOWR(DRM_COMMAND_BASE, struct adapter_monitor_info)
#define DRM_IOCTL_IDD_MONITOR_DISCONNECT         DRM_IOWR(DRM_COMMAND_BASE + 1, struct adapter_monitor_info)
#define DRM_IOCTL_IDD_REQUEST_FRAME              DRM_IOWR(DRM_COMMAND_BASE + 2, struct frame_monitor_info)

struct adapter_monitor_info {
    int width;  // IN
	int height; // IN
	int hertz;  // IN
};

struct frame_monitor_info {
	unsigned int connectorIndex;   // IN
	void* hDriverHandle;           // OUT
};
