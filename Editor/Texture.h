#ifndef __TEXTURE_H__
#define __TEXTURE_H__

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

	uint16_t						_texture_type;

	uint32_t						_texture_id;
	uint64_t						_texture_handle;

	std::string						_name;

public:
	Texture(const char* file, std::string name, uint32_t tex_index, uint32_t wrap, uint32_t filter);
	~Texture();

	uint32_t&							GetWrap();
	uint32_t&							GetFilter();
	uint16_t&							GetTextureType();
	uint32_t&							GetTextureID();
	uint64_t&							GetTextureHandle();
};

#endif