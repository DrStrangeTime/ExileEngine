#include "RenderPipeline.h"

std::shared_ptr<RenderMode>& RenderPipeline::GetRenderObject()
{
	return _render_object;
}
