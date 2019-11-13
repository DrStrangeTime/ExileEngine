#include "GLRenderPipeline.h"

GLRenderPipeline::GLRenderPipeline(uint32_t render_mode)
{
	Initialise(render_mode);
}

void GLRenderPipeline::Initialise(uint32_t render_mode)
{
	render_mode == USE_FORWARD ? _render_object = std::make_shared<GLForwardRenderer>() : _render_object = std::make_shared<GLDeferredRenderer>();

#ifdef _DEBUG
	if (!_render_object)
	{
		ExCore::Logger::PrintErr("Failed to initialise GLRenderPipeline!");
		return;
	}

	ExCore::Logger::PrintInfo("RENDER_INFO::API::OPENGL");
#endif

	ContentManager::Initialise();
}

void GLRenderPipeline::Render(double& delta)
{
	_render_object->Render(delta);
}
