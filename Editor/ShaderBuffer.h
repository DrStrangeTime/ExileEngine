#ifndef __SHADER_BUFFER_H__
#define __SHADER_BUFFER_H__

#define SHADER_TYPE_VERTEX			0x0
#define SHADER_TYPE_GEOMETRY		0x1
#define SHADER_TYPE_TESSELATION		0x2
#define SHADER_TYPE_COMPUTE			0x3


#include "Buffer.h"

class ShaderBuffer : public Buffer
{
private:
	uint16_t _type;

public:
	ShaderBuffer(uint16_t type, uint32_t program);
	~ShaderBuffer();

	uint16_t& GetType();

	void Create() override;
	void Destroy() override;
	void Bind() override;
};

#endif