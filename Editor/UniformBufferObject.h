#ifndef __UNIFORM_BUFFER_OBJECT_H__
#define __UNIFORM_BUFFER_OBJECT_H__

#include "Buffer.h"
#include "UniformBlockElement.h"

class UniformBufferObject : public Buffer
{
private:
	GLenum								_usage;
	uint32_t							_uniform_bind_index;
	std::vector<uint32_t>				_offset_data;
	std::vector<UniformBlockElement>	_uniform_block_data;

public:
	UniformBufferObject(uint32_t uniform_bind_index, std::vector<UniformBlockElement>& uniform_block_data, GLenum usage);
	~UniformBufferObject();

	uint32_t&							GetUniformBindIndex();
	std::vector<UniformBlockElement>&	GetUniformBlockData();

	void								SetUniformData(uint32_t element_index, float* data);
	void								BufferSubData(uint32_t element_index);	// Upload data dynamically
	void								BufferData();
	static void							BindBufferRange(uint32_t buffer_index, uint32_t buffer_object, uint32_t offset, size_t size); // Binds statically without uploading data

	virtual void						Create() override;
	virtual void						Destroy() override;
	virtual void						Bind() override;
};

#endif