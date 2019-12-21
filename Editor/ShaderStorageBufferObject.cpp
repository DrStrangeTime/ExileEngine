#include "ShaderStorageBufferObject.h"

ShaderStorageBufferObject::ShaderStorageBufferObject(uint32_t block_index, GLsizeiptr initial_size)
{
	_buffer_size = initial_size;
	_block_index = block_index;

	Create();
}

ShaderStorageBufferObject::~ShaderStorageBufferObject()
{
	Destroy();
}

uint32_t& ShaderStorageBufferObject::GetBlockIndex()
{
	return _block_index;
}

void ShaderStorageBufferObject::WriteData(const void* src)
{
	Bind();
	GLvoid* p = glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_WRITE_ONLY);
	memcpy(p, src, sizeof(src));
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
}

void ShaderStorageBufferObject::WriteDataRange(GLintptr offset, GLsizeiptr length, const void* src)
{
	Bind();
	GLvoid* p = glMapBufferRange(GL_SHADER_STORAGE_BUFFER, offset, length, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT);
	memcpy(p, src, sizeof(src));
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
}

void ShaderStorageBufferObject::ReadData(void* src)
{
	Bind();
	GLvoid* p = glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_READ_ONLY);
	memcpy(src, p, sizeof(src));
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
}

void ShaderStorageBufferObject::Create()
{
	glGenBuffers(1, &_buffer_object);

#ifdef _DEBUG
	if (!_buffer_object)
	{
		ExLogErr("Shader storage buffer object failed to initialise!");
		return;
	}
#endif

	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, _block_index, _buffer_object);
	glBufferData(GL_SHADER_STORAGE_BUFFER, _buffer_size, NULL, GL_DYNAMIC_DRAW);
}

void ShaderStorageBufferObject::Destroy()
{
	glDeleteBuffers(1, &_buffer_object);
}

void ShaderStorageBufferObject::Bind()
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, _buffer_object);
}
