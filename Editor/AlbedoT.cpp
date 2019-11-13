#include "AlbedoT.h"
#include "ContentManager.h"

AlbedoT::AlbedoT(uint32_t program, const char* file, std::string name, uint32_t wrap, uint32_t filter, uint32_t mat_id)
{
	uint32_t id = TextureLoader::LoadTexture2D(file, wrap, filter);
	_texture_buffer = std::make_unique<TextureBuffer>(id);

	_name = name;
	_wrap = wrap;
	_filter = filter;

	_uniform = glGetUniformLocation(program, ("albedoT[" + std::to_string(ContentManager::albedo_textures.size()-1) + "]").c_str());
}

void AlbedoT::Bind()
{
	glActiveTexture(GL_TEXTURE0 + TEXTURE_ALBEDO);
	Texture::Bind();

	glUniform1i(_uniform, TEXTURE_ALBEDO);
}
