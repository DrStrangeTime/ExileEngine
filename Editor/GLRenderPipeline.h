#ifndef __GL_RENDER_PIPELINE_H__
#define __GL_RENDER_PIPELINE_H__

#include "GLForwardRenderer.h"
#include "GLDeferredRenderer.h"

class GLRenderPipeline
{
private:
	static std::shared_ptr<Renderer>	_renderer;

public:
	static std::shared_ptr<Renderer>& GetRenderer();
};

#endif