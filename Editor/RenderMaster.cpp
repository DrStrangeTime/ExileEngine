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
		if (((_flags & USE_FORWARD) == USE_FORWARD) || ((_flags & USE_DEFERRED) == USE_DEFERRED))
		{
			_render_pipeline = std::make_shared<GLRenderPipeline>(((_flags & USE_FORWARD) == USE_FORWARD) ? USE_FORWARD : USE_DEFERRED);
			return;
		}

		_render_pipeline = std::make_shared<GLRenderPipeline>(USE_FORWARD);

#ifdef _DEBUG
		ExCore::Logger::PrintWar("Failed to read render mode! Assigning render mode to 'Forward' by default!");
#endif
	}
	else
	{
		_render_pipeline = std::make_shared<GLRenderPipeline>(USE_FORWARD);

#ifdef _DEBUG
		ExCore::Logger::PrintWar("Value of render api was not detected! Assigning render api to 'OpenGL' by default!");
#endif
	}
}

void RenderMaster::Render(double& delta)
{
	_render_pipeline->Render(delta);
}

uint32_t						RenderMaster::_flags = 0;
std::shared_ptr<RenderPipeline>	RenderMaster::_render_pipeline;