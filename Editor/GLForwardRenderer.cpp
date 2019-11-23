#include "GLForwardRenderer.h"


GLForwardRenderer::GLForwardRenderer()
{
	Initialise();
}

void GLForwardRenderer::LoadShaders(std::vector<uint16_t> shader_indices)
{
#ifdef _DEBUG
	if (shader_indices.empty())
	{
		ExCore::Logger::PrintWar("GLForwardRenderer shader list is empty!");
		return;
	}
#endif

	for (auto i = 0; i < shader_indices.size(); ++i)
	{
		switch (shader_indices[i])
		{
		case SHADER_DIFFUSE_FORWARD:
			_shaders.emplace_back(std::make_shared<DiffuseSF>());
			break;
		}
	}

	std::sort(_shaders.begin(), _shaders.end());

#ifdef _DEBUG
	ExCore::Logger::PrintInfo("RENDER_INFO::MODE::FORWARD");
#endif
}

void GLForwardRenderer::Initialise()
{
	LoadShaders({ SHADER_DIFFUSE_FORWARD });
}

void GLForwardRenderer::Render(double& delta)
{
	// 0: CAMERA + GEOMETRY + LIGHTING
	_shaders[SHADER_DIFFUSE_FORWARD]->Bind();
	//World::map->BindPlayerController();
	World::map->BindAllData();
	

	// 1: PARTICLE SYSTEM PASS


	// 2: GUI PASS


	// 3: ...
}
