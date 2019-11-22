#include "Texture.h"

Texture::Texture(uint32_t program, const char* file, std::string name, uint32_t tex_index, uint32_t wrap, uint32_t filter)
{
	uint32_t id = TextureLoader::LoadTexture2D(file, wrap, filter);
	_texture_buffer = std::make_shared<TextureBuffer>(id);

	_name = name;
	_wrap = wrap;
	_filter = filter;
	_texture_index = tex_index;

	switch (tex_index)
	{
	case (TEXTURE_ALBEDO):
		_uniform = glGetUniformLocation(program, "albedoT");
		break;
	default:
#ifdef _DEBUG
		ExLogErr("Failed to recognise texture index!");
		return;
#endif
	}
}

uint32_t& Texture::GetWrap()
{
	return _wrap;
}

uint32_t& Texture::GetFilter()
{
	return _filter;
}

uint16_t& Texture::GetTextureIndex()
{
	return _texture_index;
}

uint16_t& Texture::GetTextureType()
{
	return _texture_type;
}

std::shared_ptr<TextureBuffer>& Texture::GetTextureBuffer()
{
	return _texture_buffer;
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + _texture_index);
	_texture_buffer->Bind();
	glUniform1i(_uniform, _texture_index);
}
