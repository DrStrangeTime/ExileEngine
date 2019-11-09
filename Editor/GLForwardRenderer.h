#ifndef __GL_FORWARD_RENDERER_H__
#define __GL_FORWARD_RENDERER_H__

// Sorted macro definitions (must be in rendering order)
#define SHADER_INDEX_DIFFUSE	static_cast<uint16_t>(0)


#include "GLRenderMode.h"


class GLForwardRenderer : public GLRenderMode
{
public:
	GLForwardRenderer();

	virtual void LoadShaders(std::vector<uint16_t> shader_indices) override;
	virtual void Initialise() override;
	virtual void Render(double& delta) override;
};

#endif