#ifndef __GL_RENDER_MODE_H__
#define __GL_RENDER_MODE_H__

#include "RenderMode.h"
#include "Shader.h"

class GLRenderMode : public RenderMode
{
protected:
	std::vector<std::shared_ptr<Shader>>	_shaders;	// Stores all OpenGL shaders
	std::vector<std::shared_ptr<Shader>>	_active_shaders;	// Only stores shaders that are being used

public:
	GLRenderMode() {}
	virtual ~GLRenderMode() {}

	std::vector<std::shared_ptr<Shader>>&	GetShaders();
	std::vector<std::shared_ptr<Shader>>&	GetActiveShaders();

	virtual void LoadShaders(std::vector<uint16_t> shader_indices) override {}
	virtual void Initialise() override {}
	virtual void Render(double& delta) override {}
};

#endif