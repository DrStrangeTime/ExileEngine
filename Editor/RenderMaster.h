#ifndef __RENDER_MASTER_H__
#define __RENDER_MASTER_H__

#include "RenderPipeline.h"
#include "GLRenderPipeline.h"


/* This class will render data from a RenderPipeline object, 
   and be represented as the core engine rendering system.*/

class RenderMaster
{
private:
	static uint32_t								_flags;
	static std::shared_ptr<RenderPipeline>		_render_pipeline;

public:
	static uint32_t&							GetRenderFlags();
	static std::shared_ptr<RenderPipeline>&		GetRenderPipeline();
	
	static void Initialise(uint32_t renderer_hints);
	static void AssignRenderPipeline(uint32_t renderer_hints);
	static void Render(double &delta);
};

#endif