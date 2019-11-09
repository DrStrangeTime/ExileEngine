#ifndef __GL_RENDER_PIPELINE_H__
#define __GL_RENDER_PIPELINE_H__

#include "RenderPipeline.h"
#include "GLForwardRenderer.h"
#include "GLDeferredRenderer.h"

class GLRenderPipeline : public RenderPipeline
{
public:
	GLRenderPipeline(uint32_t render_mode);

	virtual void	Initialise(uint32_t render_mode) override;
	virtual void	Render(double& delta) override;
};

#endif