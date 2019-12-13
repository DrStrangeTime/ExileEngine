#include "FloatVertexBufferObject.h"

FloatVertexBufferObject::FloatVertexBufferObject(VertexData& vertex_data, uint32_t location_offset)
{
	_buffer_size = 0;
	_buffer_type = GL_ARRAY_BUFFER;
	_draw_type = GL_STATIC_DRAW;
	_vertex_data = vertex_data;
	_num_vertex_elements = static_cast<uint16_t>(vertex_data.vertexElements.size());
	_location_offset = location_offset;
}

void FloatVertexBufferObject::Create()
{
#ifdef _DEBUG
	if (_vertex_data.vertexElements.empty())
	{
		ExCore::Logger::PrintErr("Vertex element list is empty!");
		return;
	}
#endif

	_packed_vertex_data = VertexOptimiser::PackSingleVertex(_vertex_data);	// Store vertex array sets into one vertex array

	glGenBuffers(1, &_buffer_object);
	glBindBuffer(GL_ARRAY_BUFFER, _buffer_object);
	glBufferData(GL_ARRAY_BUFFER, _packed_vertex_data.size() * SIZE_OF_FLOAT, &_packed_vertex_data[0], GL_STATIC_DRAW);

	uint32_t it = 0;
	uintptr_t offset = 0;
	for (const VertexElement& ve : _vertex_data.vertexElements)
	{
		glEnableVertexAttribArray(_location_offset + it);
		glVertexAttribPointer(_location_offset + it, ve.componentSize, GL_FLOAT, GL_FALSE, _vertex_data.stride * SIZE_OF_FLOAT, (void*)(offset));

		glVertexAttribDivisor(_location_offset + it, ve.genericRate);

		offset += (ve.componentSize * SIZE_OF_FLOAT);	// Calculate for the next array offset
		++it;	// Increment current attrib index
	}

	_buffer_size = offset;	// Assign buffer size


#ifdef _DEBUG
	if (_buffer_object == NULL)
		ExCore::Logger::PrintErr("Vertex buffer object failed to generate!");
#endif
}

VertexData& FloatVertexBufferObject::GetVertexData()
{
	return _vertex_data;
}

std::vector<float>& FloatVertexBufferObject::GetPackedVertexData()
{
	return _packed_vertex_data;
}

void FloatVertexBufferObject::Bind()
{
	VertexBufferObject::Bind();
}
