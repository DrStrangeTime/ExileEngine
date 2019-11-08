#ifndef __RENDER_MASTER_H__
#define __RENDER_MASTER_H__

#define API_OPENGL	0x0
#define API_VULKAN	0x1

#include "GLRenderPipeline.h"

/* This class will filter all of render data using a specific render mode and render API */
class RenderMaster
{
private:
	static uint32_t _api;
	static uint32_t _mode;

public:

};

#endif