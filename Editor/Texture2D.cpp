#include "Texture2D.h"

Texture2D::Texture2D(uint32_t& shader_program, uint16_t texture_index, uint32_t texture_id)
{
	// Switch statement here
	_texture_buffer = std::make_unique<TextureBuffer>(shader_program, texture_id, TEXTURE_INDEX_ALBEDO, "Diffuse");
}

uint16_t& Texture2D::GetTextureIndex()
{
	return _texture_index;
}

std::unique_ptr<TextureBuffer>& Texture2D::GetTextureBuffer()
{
	return _texture_buffer;
}

void Texture2D::Bind()
{
	_texture_buffer->Bind();
}
