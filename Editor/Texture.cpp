#include "Texture.h"

Texture::Texture(uint32_t& shader_program, uint32_t tex_id, uint32_t active_index, const char* uniform_name)
{
	_buffer_object = tex_id;
	_active_index = active_index;

	glUniform1i(glGetUniformLocation(shader_program, uniform_name), 0);

	Create();
}

Texture::~Texture()
{
	Destroy();
}

void Texture::Create()
{
#ifdef _DEBUG
	if (_buffer_object == NULL)
		ExCore::Logger::PrintErr("Texture buffer is invalid!");
#endif
}

void Texture::Destroy()
{
	glDeleteTextures(1, &_buffer_object);
}

void Texture::Bind()
{
	glActiveTexture(_active_index);
	glBindTexture(GL_TEXTURE_2D, _buffer_object);
}
