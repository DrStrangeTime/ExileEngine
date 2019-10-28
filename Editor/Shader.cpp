#include "Shader.h"


Shader::Shader(uint32_t program)
{
	_buffer_object = program;
	Create();
}

Shader::~Shader()
{
	Destroy();
}

void Shader::Create()
{
#ifdef _DEBUG
	if (_buffer_object == NULL)
		ExCore::Logger::PrintErr("Shader program is not valid!");
#endif
}

void Shader::Destroy()
{
	glDeleteProgram(_buffer_object);
}

void Shader::Bind()
{
	glUseProgram(_buffer_object);
}
