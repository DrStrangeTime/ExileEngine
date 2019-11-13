#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "Headers.h"

struct VertexElement {
	uint16_t				componentSize;
	std::vector<float>		data;

	VertexElement() : componentSize(0) {}
	VertexElement(uint16_t comp_size, std::vector<float> vertex_data)
	{
		componentSize = comp_size;
		data = vertex_data;
	}
};

struct VertexData {
	uint16_t					stride;
	std::vector<VertexElement>	vertexElements;

	inline VertexData() { stride = 0; }
	inline VertexData(uint16_t _stride, std::vector<VertexElement> _vertex_elements) {
		stride = _stride;
		vertexElements = _vertex_elements;
	}
};

#endif