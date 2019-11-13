#include "Texture.h"

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

std::unique_ptr<TextureBuffer>& Texture::GetTextureBuffer()
{
	return _texture_buffer;
}

void Texture::Bind()
{
	_texture_buffer->Bind();
}
