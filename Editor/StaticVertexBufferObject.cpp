#include "StaticVertexBufferObject.h"

StaticVertexBufferObject::StaticVertexBufferObject(VertexData& vertex_data)
{
	Initialise(vertex_data);

	_draw_type = GL_STATIC_DRAW;
}

void StaticVertexBufferObject::Create()
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

	_packed_vertex_data = VertexOptimiser::PackSingleVertex(_vertex_data);	// Store vertex array sets into one vertex array

	glGenBuffers(1, &_buffer_object);
	glBindBuffer(GL_ARRAY_BUFFER, _buffer_object);
	glBufferData(GL_ARRAY_BUFFER, _packed_vertex_data.size() * SIZE_OF_FLOAT, &_packed_vertex_data[0], GL_STATIC_DRAW);

	uint32_t it = 0;
	uintptr_t offset = 0;
	for (const VertexElement& ve : _vertex_data.vertexElements)
	{
		glVertexAttribPointer(it, ve.componentSize, GL_FLOAT, GL_FALSE, _vertex_data.stride * SIZE_OF_FLOAT, (void*)(offset));
		glEnableVertexAttribArray(it);

		offset += (ve.componentSize * SIZE_OF_FLOAT);	// Calculate for the next array offset
		++it;	// Increment current attrib index
	}

	_buffer_size = offset;	// Assign buffer size

#ifdef _DEBUG
	if (_buffer_object == NULL)
		ExCore::Logger::PrintErr("Vertex buffer object failed to generate!");
#endif
}

void StaticVertexBufferObject::Bind()
{
	VertexBufferObject::Bind();
}
