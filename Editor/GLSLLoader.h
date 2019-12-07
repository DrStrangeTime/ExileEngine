#ifndef __SHDAER_LOADER_H__
#define __SHADER_LOADER_H__

#define ARB_shading_language_include

#include "Headers.h"

class GLSLLoader
{
public:
	static uint32_t CreateShader(std::map<uint32_t, const GLchar*>& shader_stages);
};

#endif