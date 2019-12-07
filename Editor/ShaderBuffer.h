#ifndef __SHADER_BUFFER_H__
#define __SHADER_BUFFER_H__

#define SHADER_TYPE_VERTEX			0x0
#define SHADER_TYPE_GEOMETRY		0x1
#define SHADER_TYPE_TESSELATION		0x2
#define SHADER_TYPE_COMPUTE			0x3


#include "Buffer.h"

class ShaderBuffer : public Buffer
{
public:
	ShaderBuffer(uint32_t program);
	~ShaderBuffer();

	void Create() override;
	void Destroy() override;
	void Bind() override;
};

#endif