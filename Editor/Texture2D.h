#ifndef __TEXTURE_2D_H__
#define __TEXTURE_2D_H__

#include "Object.h"
#include "TextureBuffer.h"
#include "TextureLoader.h"

#define TEXTURE_INDEX_ALBEDO	static_cast<uint16_t>(0)


class Texture2D : public Object
{
private:
	uint16_t						_texture_index;
	std::unique_ptr<TextureBuffer>	_texture_buffer;

public:
	Texture2D(uint32_t& shader_program, uint16_t texture_index, uint32_t texture_id);

	uint16_t&						GetTextureIndex();
	std::unique_ptr<TextureBuffer>& GetTextureBuffer();

	void							Bind();
};

#endif