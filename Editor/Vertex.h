#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "Headers.h"

struct VertexElement {
	uint16_t			genericRate;
	uint16_t			componentSize;
	std::vector<float>	data;

	VertexElement() : componentSize(0) {}
	VertexElement(uint16_t comp_size, uint16_t rate)
	{
		componentSize = comp_size;
		genericRate = rate;
	}
	VertexElement(uint16_t comp_size, uint16_t rate, std::vector<float> vertex_data)
	{
		componentSize = comp_size;
		genericRate = rate;
		data = vertex_data;
	}
};

struct VertexData {
	uint32_t					size;
	uint16_t					stride;
	std::vector<VertexElement>	vertexElements;

	inline VertexData() { stride = 0; }
	inline VertexData(uint32_t _size, uint16_t _stride, std::vector<VertexElement> _vertex_elements) {
		size = _size;
		stride = _stride;
		vertexElements = _vertex_elements;
	}
};

struct PackedVertex {
	glm::vec3	position;
	glm::vec3	texcoord;
	glm::vec3	normal;

	bool operator<(const PackedVertex that) const
	{
		return memcmp((void*)this, (void*)&that, sizeof(PackedVertex)) > 0;
	};
};

#endif