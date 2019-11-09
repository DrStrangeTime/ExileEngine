#include "ShaderBuffer.h"


ShaderBuffer::ShaderBuffer(uint16_t type, uint32_t program)
{
	_type = type;
	_buffer_object = program;
	
	Create();
}

ShaderBuffer::~ShaderBuffer()
{
	Destroy();
}

uint16_t& ShaderBuffer::GetType()
{
	return _type;
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
