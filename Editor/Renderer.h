#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "Headers.h"

#define RENDER_MODE_OPENGL_FORWARD		0x0
#define RENDER_MODE_OPENGL_DEFERRED		0x1
//#define RENDER_MODE_VULKAN_FORWARD		0x2
//#define RENDER_MODE_VULKAN_DEFERRED		0x3


/* The abstract renderer class to allow toggling between different rendering methods*/
class Renderer
{
protected:
	uint16_t	_renderMode;

public:

	uint16_t& GetRenderMode();

	void SetRenderMode(uint16_t value);
};

#endif