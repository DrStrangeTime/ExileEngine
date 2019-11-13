#include "Shader.h"

uint16_t& Shader::GetShaderIndex()
{
	return _shader_index;
}

uint32_t& Shader::GetProgram()
{
	return _shader_buffer->GetBufferObject();
}

std::shared_ptr<ShaderBuffer>& Shader::GetShaderBuffer()
{
	return _shader_buffer;
}

std::vector<uint32_t>& Shader::GetUniforms()
{
	return _uniforms;
}

void Shader::Bind()
{
	_shader_buffer->Bind();
}
