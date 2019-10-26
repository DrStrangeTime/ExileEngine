#include "IndexBufferObject.h"


IndexBufferObject::IndexBufferObject(std::vector<uint32_t> index_data)
{
	_buffer_type = GL_ELEMENT_ARRAY_BUFFER;
	_buffer_size = index_data.size() * SIZE_OF_UINT32;
	_index_data = index_data;
}

IndexBufferObject::~IndexBufferObject()
{
	Destroy();
}

void IndexBufferObject::Create()
{
#ifdef _DEBUG
	if (_index_data.empty())
	{
		ExCore::Logger::PrintErr("Index data container is empty!");
		return;
	}
#endif

	glGenBuffers(1, &_buffer_object);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffer_object);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _buffer_size, &_index_data[0], GL_STATIC_DRAW);

#ifdef _DEBUG
	if (_buffer_object == NULL)
		ExCore::Logger::PrintErr("Index buffer object failed to generate!");
#endif
}

void IndexBufferObject::Destroy()
{
	glDeleteBuffers(1, &_buffer_object);
}

void IndexBufferObject::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffer_object);
}

GLsizei& IndexBufferObject::GetIndexSize()
{
	return _index_size;
}

std::vector<uint32_t>& IndexBufferObject::GetIndexData()
{
	return _index_data;
}
