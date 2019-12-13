#include "Texture.h"

Texture::Texture(const char* file, std::string name, uint32_t tex_type, uint32_t wrap, uint32_t filter)
{
	_texture_id = TextureLoader::LoadTexture2D(file, wrap, filter);
	_texture_handle = glGetTextureHandleARB(_texture_id);

	glMakeTextureHandleResidentARB(_texture_handle);

	_name = name;
	_wrap = wrap;
	_filter = filter;
	_texture_type = tex_type;
}

Texture::~Texture()
{
	glDeleteTextures(1, &_texture_id);
}

uint32_t& Texture::GetWrap()
{
	return _wrap;
}

uint32_t& Texture::GetFilter()
{
	return _filter;
}

uint16_t& Texture::GetTextureType()
{
	return _texture_type;
}

uint32_t& Texture::GetTextureID()
{
	return _texture_id;
}

uint64_t& Texture::GetTextureHandle()
{
	return _texture_handle;
}
