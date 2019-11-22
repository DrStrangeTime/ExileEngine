#ifndef __TEXTURE_BUFFER_H__
#define __TEXTURE_BUFFER_H__

#include "Buffer.h"

/* */
class TextureBuffer : public Buffer
{
public:
	TextureBuffer() = default;
	TextureBuffer(uint32_t tex_id);
	~TextureBuffer();

	void Create() override;
	void Destroy() override;
	void Bind() override;
};

#endif