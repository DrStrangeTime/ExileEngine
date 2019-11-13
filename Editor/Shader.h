#ifndef __SHADER_H__
#define __SHADER_H__

#include "ShaderBuffer.h"
#include "GLSLLoader.h"

#define SHADER_DIFFUSE_FORWARD	0x0


class Shader
{
protected:
	uint16_t						_shader_index;
	std::shared_ptr<ShaderBuffer>	_shader_buffer;
	std::vector<uint32_t>			_uniforms;

public:
	Shader() : _shader_index(0) {}

	uint16_t&						GetShaderIndex();
	uint32_t&						GetProgram();
	std::shared_ptr<ShaderBuffer>&	GetShaderBuffer();
	std::vector<uint32_t>&			GetUniforms();

	virtual void					Initialise() = 0;
	virtual void					Bind();

	bool operator < (std::shared_ptr<Shader> s) const {
		return _shader_index < s->GetShaderIndex();
	}
};

#endif