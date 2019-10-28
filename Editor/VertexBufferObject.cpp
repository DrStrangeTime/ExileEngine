#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject(Vertex vertex_data)
{
	_buffer_size = 0;
	_buffer_type = GL_ARRAY_BUFFER;
	_vertex_data = vertex_data;
	_num_vertex_elements = static_cast<uint16_t>(vertex_data.vertexElements.size());
	_stride = 0;
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

	_packed_vertex_data = PackSingleVertex(_vertex_data);	// Store vertex array sets into one vertex array

	glGenBuffers(1, &_buffer_object);
	glBindBuffer(GL_ARRAY_BUFFER, _buffer_object);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_packed_vertex_data), &_packed_vertex_data[0], GL_STATIC_DRAW);

	uint32_t it = 0;
	uint32_t it_size = 0;
	for (const VertexElement& ve : _vertex_data.vertexElements)
	{
		_buffer_size = _buffer_size + sizeof(ve.data[0]);

		glEnableVertexAttribArray(it);
		glVertexAttribPointer(it, ve.componentSize, GL_FLOAT, GL_FALSE, _vertex_data.stride * SIZE_OF_FLOAT, (GLvoid*)0);

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

// Pack a subset of vertex data into one vertex array
std::vector<float> VertexBufferObject::PackSingleVertex(Vertex vertex_data)
{
	std::vector<float> opt_vertex_data;

	bool finished = false;
	auto vertex_size = _vertex_data.vertexElements[0].data.size() / _vertex_data.vertexElements[0].componentSize;
	auto attrib_size = _vertex_data.vertexElements.size();
	auto attrib_index = 0;
	auto vertex_index = 0;

	while (!finished)
	{
		// Get the current component size
		auto comp_size = _vertex_data.vertexElements[attrib_index].componentSize;

		// Add new set of data from a vertex element
		for (auto i = 0; i < comp_size; ++i) // Iterate through each vertex component
		{
			auto id = i + (vertex_index * comp_size);
			opt_vertex_data.push_back(_vertex_data.vertexElements[attrib_index].data[id]);
		}

		// Go to next attrib
		attrib_index++;

		// Rotate attrib index
		if (attrib_index > _vertex_data.vertexElements.size() - 1)
		{
			attrib_index = 0;
			vertex_index++;
		}

		// Check for last vertex
		if (vertex_index > vertex_size - 1)
			finished = true;
	}

	return opt_vertex_data;
}

Vertex& VertexBufferObject::GetVertexData()
{
	return _vertex_data;
}

std::vector<float>& VertexBufferObject::GetPackedVertexData()
{
	return _packed_vertex_data;
}


