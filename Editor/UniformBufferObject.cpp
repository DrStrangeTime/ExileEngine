#include "UniformBufferObject.h"

UniformBufferObject::UniformBufferObject(uint32_t uniform_bind_index, std::vector<BlockElement>& uniform_block_data, GLenum usage)
{
	_uniform_bind_index = uniform_bind_index;
	_uniform_block_data = uniform_block_data;
	_usage = usage;

	Create();
}

UniformBufferObject::~UniformBufferObject()
{
	Destroy();
}

uint32_t& UniformBufferObject::GetUniformBindIndex()
{
	return _uniform_bind_index;
}

std::vector<BlockElement>& UniformBufferObject::GetUniformBlockData()
{
	return _uniform_block_data;
}

void UniformBufferObject::Create()
{
	/* Calculate stride, offset and buffer size */
	uint32_t stride(0);
	for (auto i = 0; i < _uniform_block_data.size(); ++i)
	{
		_uniform_block_data[i].offset = stride * sizeof(float);
		stride += _uniform_block_data[i].comp_size;
	}

	_buffer_size = stride * sizeof(float);

	/* Generate and allocate buffer */
	glGenBuffers(1, &_buffer_object);

#ifdef _DEBUG
	if (!_buffer_object)
	{
		ExLogErr("Uniform buffer object failed to initialise!");
		return;
	}
#endif

	glBindBuffer(GL_UNIFORM_BUFFER, _buffer_object);
	glBufferData(GL_UNIFORM_BUFFER, _buffer_size, NULL, _usage);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);

	// Define range of the buffer that links to a uniform binding point
	//glBindBufferRange(GL_UNIFORM_BUFFER, _binding_point_index, _buffer_object, 0, _buffer_size);	// Buffer certain range to binding point
	glBindBufferBase(GL_UNIFORM_BUFFER, _uniform_bind_index, _buffer_object);	// Bind everything to binding point

	// Buffer subdata for each static element
	glBindBuffer(GL_UNIFORM_BUFFER, _buffer_object);

	for (auto i = 0; i < _uniform_block_data.size(); ++i)
		BufferSubData(i);

	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void UniformBufferObject::Destroy()
{
	glDeleteBuffers(1, &_buffer_object);
}

void UniformBufferObject::Bind()
{
	glBindBuffer(GL_UNIFORM_BUFFER, _buffer_object);
}

void UniformBufferObject::BufferData()
{
	for (auto i = 0; i < _uniform_block_data.size(); ++i)
		BufferSubData(i);
}

void UniformBufferObject::BufferSubData(uint32_t element_index)
{
	glNamedBufferSubDataEXT(_buffer_object, _uniform_block_data[element_index].offset, _uniform_block_data[element_index].size_in_bytes, _uniform_block_data[element_index].data);
}