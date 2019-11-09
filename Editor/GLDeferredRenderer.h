#ifndef __GL_DEFERRED_RENDERER_H__
#define __GL_DEFERRED_RENDERER_H__

#include "GLRenderMode.h"

class GLDeferredRenderer : public GLRenderMode
{
private:

public:
	GLDeferredRenderer() {}

	virtual void LoadShaders(std::vector<uint32_t> shader_indices);
	virtual void Initialise();
	virtual void Render(double& delta);
};

#endif