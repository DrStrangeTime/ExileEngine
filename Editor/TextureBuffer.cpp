#include "TextureBuffer.h"

TextureBuffer::TextureBuffer(uint32_t tex_id)
{
	_buffer_object = tex_id;

	Create();
}

TextureBuffer::~TextureBuffer()
{
	Destroy();
}

void TextureBuffer::Create()
{
#ifdef _DEBUG
	if (_buffer_object == NULL)
		ExCore::Logger::PrintErr("Texture buffer is invalid!");
#endif
}

void TextureBuffer::Destroy()
{
	glDeleteTextures(1, &_buffer_object);
}

void TextureBuffer::Bind()
{
	glBindTexture(GL_TEXTURE_2D, _buffer_object);
}
