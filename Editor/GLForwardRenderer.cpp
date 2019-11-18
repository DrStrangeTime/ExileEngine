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
			_shaders.push_back(std::make_shared<DiffuseSF>());
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

	// ---------------------------------------------------- DEFAULT CONTENT ----------------------------------------------------
	// BSP data
	ContentManager::bsps[0] = std::make_shared<Plane>(_shaders[SHADER_DIFFUSE_FORWARD]->GetProgram(), .0f, .0f, -5.f, PLANE_DIR_Z, 1.f, 1.f, 0);
	// Texture data
	ContentManager::albedo_textures.emplace_back(std::make_shared<AlbedoT>(		_shaders[SHADER_DIFFUSE_FORWARD]->GetProgram(),
																				"textures/default_a.tga",
																				"default_albedo",
																				GL_REPEAT,
																				GL_LINEAR,
																				0)); // Mat ID
	// Material data
	std::vector<std::shared_ptr<Texture>> textures = { ContentManager::albedo_textures[0] };
	ContentManager::materials.emplace_back(	std::make_shared<OpaqueFM>(			_shaders[SHADER_DIFFUSE_FORWARD]->GetProgram(),
																				"default_mat",
																				false,
																				textures));
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
