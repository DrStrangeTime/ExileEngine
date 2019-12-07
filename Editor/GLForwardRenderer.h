#ifndef __GL_FORWARD_RENDERER_H__
#define __GL_FORWARD_RENDERER_H__

#include "GLRenderMode.h"
#include "DiffuseSF.h"

#ifdef _DEBUG
	#include "NormalVisualisationS.h"
#endif


class GLForwardRenderer : public GLRenderMode
{
public:
	GLForwardRenderer();

	virtual void LoadShaders(std::vector<uint16_t> shader_indices) override;
	virtual void Initialise() override;
	virtual void Render(double& delta) override;
};

#endif