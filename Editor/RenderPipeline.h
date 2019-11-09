#ifndef __RENDER_PIPELINE_H__
#define __RENDER_PIPELINE_H__

#include "RenderMode.h"

class RenderPipeline
{
protected:
	std::shared_ptr<RenderMode>		_render_object;

public:
	std::shared_ptr<RenderMode>&	GetRenderObject();

	virtual void					Initialise(uint32_t render_mode) = 0;
	virtual void					Render(double& delta) = 0;
};

#endif