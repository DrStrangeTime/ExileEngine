#ifndef __TEXTURE_BUFFER_H__
#define __TEXTURE_BUFFER_H__

#include "Buffer.h"

/* */
class TextureBuffer : public Buffer
{
private:
	uint32_t	_width;
	uint32_t	_height;

	uint16_t	_active_index;

public:
	TextureBuffer(uint32_t& shader_program, uint32_t tex_id, uint16_t active_id, const char* uniform_name);
	~TextureBuffer();

	void Create() override;
	void Destroy() override;
	void Bind() override;
};

#endif