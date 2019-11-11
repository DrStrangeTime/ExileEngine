#include "VertexBufferObject.h"

VertexBufferObject::~VertexBufferObject()
{
	Destroy();
}

void VertexBufferObject::Destroy()
{
	glDeleteBuffers(1, &_buffer_object);
}

void VertexBufferObject::Bind()
{
	glBindBuffer(_buffer_type, _buffer_object);
}

void VertexBufferObject::Initialise(Vertex vertex_data)
{
	_buffer_size = 0;
	_buffer_type = GL_ARRAY_BUFFER;
	_vertex_data = vertex_data;
	_num_vertex_elements = static_cast<uint16_t>(vertex_data.vertexElements.size());
}

Vertex& VertexBufferObject::GetVertexData()
{
	return _vertex_data;
}

std::vector<float>& VertexBufferObject::GetPackedVertexData()
{
	return _packed_vertex_data;
}


