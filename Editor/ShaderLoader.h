#ifndef __SHDAER_LOADER_H__
#define __SHADER_LOADER_H__

#define ARB_shading_language_include


#include "Headers.h"


class ShaderLoader
{
private:
	GLuint	_program;

public:

	ShaderLoader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~ShaderLoader();

	void Bind();
};

#endif