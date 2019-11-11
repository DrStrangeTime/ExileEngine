#include "GLRenderPipeline.h"

GLRenderPipeline::GLRenderPipeline(uint32_t render_mode)
{
	Initialise(render_mode);
}

void GLRenderPipeline::Initialise(uint32_t render_mode)
{
	render_mode == USE_FORWARD ? _render_object = std::make_shared<GLForwardRenderer>() : _render_object = std::make_shared<GLDeferredRenderer>();
}

void GLRenderPipeline::Render(double& delta)
{
	_render_object->Render(delta);
}
