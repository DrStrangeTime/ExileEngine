#include "UniformBufferObject.h"

UniformBufferObject::UniformBufferObject(std::vector<UniformBlockElement> uniform_block_data, uint32_t stride, GLenum usage)
{
	_uniform_block_data = _uniform_block_data;
	_usage = usage;
	_stride = stride;

	Create();
}

UniformBufferObject::~UniformBufferObject()
{
	Destroy();
}

std::vector<UniformBlockElement>& UniformBufferObject::GetUniformData()
{
	return _uniform_block_data;
}

void UniformBufferObject::Create()
{
	/*glGenBuffers(1, &_buffer_object);
	glBindBuffer(GL_UNIFORM_BUFFER, _buffer_object);
	glBufferData(GL_UNIFORM_BUFFER, (_uniform_data.size() * _stride) * SIZE_OF_FLOAT, NULL, _usage);

	glBindBufferRange(GL_UNIFORM_BUFFER, 0, _buffer_object, 0, (_uniform_data.size() * _stride) * SIZE_OF_FLOAT);

	for (auto i = 0; i < _uniform_data.size(); ++i)
		glBufferSubData(GL_UNIFORM_BUFFER, 0, )*/
}

void UniformBufferObject::Destroy()
{
	glDeleteBuffers(1, &_buffer_object);
}

void UniformBufferObject::Bind()
{

}
