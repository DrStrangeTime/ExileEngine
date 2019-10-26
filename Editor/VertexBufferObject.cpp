#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject(Vertex vertex_data)
{
	_buffer_size = 0;
	_buffer_type = GL_ARRAY_BUFFER;
	_vertex_data = vertex_data;
	_num_vertex_elements = static_cast<uint16_t>(vertex_data.vertexElements.size());
}

VertexBufferObject::~VertexBufferObject()
{
	Destroy();
}

void VertexBufferObject::Create()
{
#ifdef _DEBUG
	if (_vertex_data.vertexElements.empty())
	{
		ExCore::Logger::PrintErr("Vertex element list is empty!");
		return;
	}

	for (const VertexElement& ve : _vertex_data.vertexElements)
	{
		if (ve.data.empty())
		{
			ExCore::Logger::PrintErr("Vertex element contains NULL data!");
			return;
		}
	}
#endif

	glGenBuffers(1, &_buffer_object);
	glBindBuffer(GL_ARRAY_BUFFER, _buffer_object);

	uint32_t it = 0;
	uint32_t it_size = 0;
	for (const VertexElement& ve : _vertex_data.vertexElements)
	{
		_buffer_size = _buffer_size + sizeof(ve.data[0]);

		glBufferSubData(GL_ARRAY_BUFFER, it_size, sizeof(ve.data), &ve.data);
		glEnableVertexAttribArray(it);
		glVertexAttribPointer(it, ve.componentSize, GL_FLOAT, GL_FALSE, ve.componentSize * SIZE_OF_FLOAT, (GLvoid*)0);

		++it;
		it_size += sizeof(ve.data);
	}

#ifdef _DEBUG
	if (_buffer_object == NULL)
		ExCore::Logger::PrintErr("Vertex buffer object failed to generate!");
#endif
}

void VertexBufferObject::Destroy()
{
	glDeleteBuffers(1, &_buffer_object);
}

void VertexBufferObject::Bind()
{
	glBindBuffer(_buffer_type, _buffer_object);
}

Vertex& VertexBufferObject::GetVertexData()
{
	return _vertex_data;
}
