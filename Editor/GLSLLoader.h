#ifndef __SHDAER_LOADER_H__
#define __SHADER_LOADER_H__

#define ARB_shading_language_include

#include "Headers.h"


class GLSLLoader
{
public:
	static uint32_t LoadVertFrag(const GLchar* vertexPath, const GLchar* fragmentPath);
};

#endif