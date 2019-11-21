#ifndef __UNIFORM_BUFFER_OBJECT_H__
#define __UNIFORM_BUFFER_OBJECT_H__

#include "Buffer.h"
#include "UniformBlockElement.h"

class UniformBufferObject : public Buffer
{
private:
	uint32_t							_stride;
	GLenum								_usage;
	std::vector<UniformBlockElement>	_uniform_block_data;

public:
	UniformBufferObject(std::vector<UniformBlockElement> uniform_block_data, uint32_t stride, GLenum usage);
	~UniformBufferObject();

	std::vector<UniformBlockElement>&	GetUniformData();

	virtual void						Create();
	virtual void						Destroy();
	virtual void						Bind();
};

#endif