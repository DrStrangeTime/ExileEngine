#include "RenderMaster.h"

uint32_t& RenderMaster::GetRenderFlags()
{
	return _flags;
}

std::shared_ptr<RenderPipeline>& RenderMaster::GetRenderPipeline()
{
	return _render_pipeline;
}

void RenderMaster::Initialise(uint32_t renderer_hints)
{
	_flags = renderer_hints;

	AssignRenderPipeline(renderer_hints);
}

void RenderMaster::AssignRenderPipeline(uint32_t renderer_hints)
{
	if ((_flags & USE_OPENGL) == USE_OPENGL)
	{
		_render_pipeline = std::make_shared<GLRenderPipeline>(((_flags & USE_FORWARD) == USE_FORWARD) ? USE_FORWARD : USE_DEFERRED);
		return;

#ifdef _DEBUG
		ExCore::Logger::PrintErr("Failed to read render mode!");
#endif
	}
	/*else if ((_flags & USE_VULKAN) == USE_VULKAN)
	{
		_render_pipeline = std::make_shared<VKRenderPipeline>(((_flags & USE_FORWARD) == USE_FORWARD) ? USE_FORWARD : USE_DEFERRED);
		return;

#ifdef _DEBUG
		ExCore::Logger::PrintErr("Failed to read render mode!");
#endif
	}*/
	else
	{
#ifdef _DEBUG
		ExCore::Logger::PrintErr("Value of render api is invalid! Failed to assign render pipeline!");
#endif
	}
}

void RenderMaster::Render(double& delta)
{
	_render_pipeline->Render(delta);
}

uint32_t						RenderMaster::_flags = 0;
std::shared_ptr<RenderPipeline>	RenderMaster::_render_pipeline;