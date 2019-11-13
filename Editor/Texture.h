#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "TextureBuffer.h"
#include "TextureLoader.h"

#define TEXTURE_ALBEDO		0x0
#define TEXTURE_ROUGHNESS	0x1
#define TEXTURE_METALNESS	0x2
#define TEXTURE_NORMAL		0x3

#define TEXTURE_2D			0x0
#define TEXTURE_CUBE		0x1
#define TEXTURE_HDRI		0x2


/* This class represents an interface for deriving texture types */
class Texture
{
protected:
	uint32_t						_wrap;
	uint32_t						_filter;
	uint32_t						_uniform;

	uint16_t						_texture_index;
	uint16_t						_texture_type;

	std::string						_name;

	std::unique_ptr<TextureBuffer>	_texture_buffer;

public:
	Texture() : _uniform(0), _wrap(GL_REPEAT), _filter(GL_LINEAR), _texture_index(0), _texture_type(0) {}

	uint32_t&						GetWrap();
	uint32_t&						GetFilter();
	uint16_t&						GetTextureIndex();
	uint16_t&						GetTextureType();
	std::unique_ptr<TextureBuffer>& GetTextureBuffer();

	virtual void					Bind();
};

#endif