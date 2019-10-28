#ifndef __SHADER_H__
#define __SHADER_H__

#include "Buffer.h"

class Shader : public Buffer
{
public:
	Shader(uint32_t program);
	~Shader();

	void Create() override;
	void Destroy() override;
	void Bind() override;
};

#endif