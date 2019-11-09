#include "TextureBuffer.h"

TextureBuffer::TextureBuffer(uint32_t& shader_program, uint32_t tex_id, uint16_t active_index, const char* uniform_name)
{
	_buffer_object = tex_id;
	_active_index = active_index;

	glUniform1i(glGetUniformLocation(shader_program, uniform_name), 0);

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
	glActiveTexture(_active_index);
	glBindTexture(GL_TEXTURE_2D, _buffer_object);
}
