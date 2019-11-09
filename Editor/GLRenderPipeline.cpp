#include "GLRenderPipeline.h"

GLRenderPipeline::GLRenderPipeline(uint32_t render_mode)
{
	Initialise(render_mode);
}

void GLRenderPipeline::Initialise(uint32_t render_mode)
{
	if (render_mode == USE_FORWARD || render_mode == USE_DEFERRED)
	{
		render_mode == USE_FORWARD ? _render_object = std::make_shared<GLForwardRenderer>() : _render_object = std::make_shared<GLDeferredRenderer>();
		return;
	}

#ifdef _DEBUG
	ExCore::Logger::PrintErr("Invalid GL render mode!");
#endif
}

void GLRenderPipeline::Render(double& delta)
{
	_render_object->Render(delta);
}
