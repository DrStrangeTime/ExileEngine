#include "ShaderBuffer.h"


ShaderBuffer::ShaderBuffer(uint32_t program)
{
	_buffer_object = program;
	
	Create();
}

ShaderBuffer::~ShaderBuffer()
{
	Destroy();
}

void ShaderBuffer::Create()
{
#ifdef _DEBUG
	if (_buffer_object == NULL)
		ExCore::Logger::PrintErr("Shader program is not valid!");
#endif
}

void ShaderBuffer::Destroy()
{
	glDeleteProgram(_buffer_object);
}

void ShaderBuffer::Bind()
{
	glUseProgram(_buffer_object);
}
