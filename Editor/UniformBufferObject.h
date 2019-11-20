#ifndef __UNIFORM_BUFFER_OBJECT_H__
#define __UNIFORM_BUFFER_OBJECT_H__

#include "Buffer.h"

class UniformBufferObject : public Buffer
{
public:
	UniformBufferObject();
	~UniformBufferObject();

	virtual void	Create();
	virtual void	Destroy();
	virtual void	Bind();
};

#endif