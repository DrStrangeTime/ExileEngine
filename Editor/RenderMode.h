#ifndef __RENDER_MODE_H__
#define __RENDER_MODE_H__

// Hint macro definitions
#define USE_OPENGL		0x1
#define USE_VULKAN		0x2
#define USE_FORWARD		0x4
#define USE_DEFERRED	0x8

#include "World.h"
#include "WorldInfo.h"

/* The abstract renderer class to allow toggling between different rendering methods*/
class RenderMode
{
protected:
	uint16_t		_render_mode;

public:
	RenderMode() : _render_mode(0) {}
	uint16_t&		GetRenderMode();

	virtual void	LoadShaders(std::vector<uint16_t> shader_indices) = 0;
	virtual void	Initialise() = 0;
	virtual void	Render(double& delta) = 0;
};

#endif