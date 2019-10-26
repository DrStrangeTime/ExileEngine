#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "Headers.h"

struct VertexElement {
	uint16_t				componentSize;
	std::vector<float>		data;

	VertexElement(uint16_t comp_size, std::vector<float> vertex_data)
	{
		componentSize = comp_size;
		data = vertex_data;
	}
};

struct Vertex {
	std::vector<VertexElement> vertexElements;

	inline Vertex() = default;
	inline Vertex(std::vector<VertexElement> ve) {
		vertexElements = ve;
	}
};

#endif