#include "GLForwardRenderer.h"

GLForwardRenderer::GLForwardRenderer()
{
	Initialise();
}

void GLForwardRenderer::LoadShaders(std::vector<uint16_t> shader_indices)
{
	for (auto i = 0; i < shader_indices.size(); ++i)
	{
		switch (shader_indices[i])
		{
		case SHADER_INDEX_DIFFUSE:
			//_shaders.push_back(std::make_shared<DiffuseForward>());
			break;
		}
	}
}

void GLForwardRenderer::Initialise()
{
	LoadShaders({ SHADER_INDEX_DIFFUSE });
}

void GLForwardRenderer::Render(double& delta)
{
	// 0: GEOMETRY + LIGHT PASS


	// 1: PARTICLE SYSTEM PASS


	// 2: GUI PASS


	// 3: ...
}
