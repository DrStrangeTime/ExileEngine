#ifndef __RENDER_MODE_H__
#define __RENDER_MODE_H__

#include "Headers.h"

#define RENDER_MODE_OPENGL_FORWARD		0x0
#define RENDER_MODE_OPENGL_DEFERRED		0x1
//#define RENDER_MODE_VULKAN_FORWARD		0x2
//#define RENDER_MODE_VULKAN_DEFERRED		0x3


/* The abstract renderer class to allow toggling between different rendering methods*/
class RenderMode
{
protected:
	uint16_t	_mode;

public:

	uint16_t& GetRenderMode();

	void SetRenderMode(uint16_t value);
};

#endif