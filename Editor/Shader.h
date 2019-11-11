#ifndef __SHADER_H__
#define __SHADER_H__

#include "Object.h"
#include "ShaderBuffer.h"
#include "GLSLLoader.h"


class Shader : public Object
{
private:
	uint16_t						_shader_index;
	std::shared_ptr<ShaderBuffer>	_shader_buffer;

public:
	Shader() : _shader_index(0) {}

	uint16_t&						GetShaderIndex();
	std::shared_ptr<ShaderBuffer>&	GetShaderBuffer();

	virtual void					Initialise(uint16_t shader_index) = 0;	// Load shader file and store to shader buffer

	void							Bind();
};

#endif