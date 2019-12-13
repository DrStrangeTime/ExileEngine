#include "Uint64VertexBufferObject.h"

Uint64VertexBufferObject::Uint64VertexBufferObject(std::vector<GLuint64>& vertex_data, uint32_t location_offset)
{
	_buffer_size = vertex_data.size() * sizeof(GLuint64);
	_buffer_type = GL_ARRAY_BUFFER;
	_draw_type = GL_STATIC_DRAW;
	_vertex_data = vertex_data;
	_num_vertex_elements = 1;
	_location_offset = location_offset;
}

void Uint64VertexBufferObject::Create()
{
#ifdef _DEBUG
	if (_vertex_data.empty())
	{
		ExCore::Logger::PrintErr("Vertex element list is empty!");
		return;
	}
#endif

	glGenBuffers(1, &_buffer_object);
	glBindBuffer(GL_ARRAY_BUFFER, _buffer_object);
	glBufferData(GL_ARRAY_BUFFER, _vertex_data.size() * sizeof(GLuint64), &_vertex_data[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(_location_offset);
	glVertexAttribLPointer(_location_offset, 1, GL_UNSIGNED_INT64_ARB, 0, 0);
}

void Uint64VertexBufferObject::Bind()
{
	VertexBufferObject::Bind();
}
