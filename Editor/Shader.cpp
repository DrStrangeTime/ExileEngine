#include "Shader.h"

uint16_t& Shader::GetShaderIndex()
{
	return _shader_index;
}

std::shared_ptr<ShaderBuffer>& Shader::GetShaderBuffer()
{
	return _shader_buffer;
}

void Shader::Bind()
{
	_shader_buffer->Bind();
}
