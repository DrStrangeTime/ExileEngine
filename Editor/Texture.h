#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "Buffer.h"

/* */
class Texture : public Buffer
{
private:
	uint32_t	_width;
	uint32_t	_height;

	uint32_t	_active_index;

public:
	Texture(uint32_t& shader_program, uint32_t tex_id, uint32_t active_id, const char* uniform_name);
	~Texture();

	void Create() override;
	void Destroy() override;
	void Bind() override;
};

#endif