#ifndef __VERTEX_OPTIMISER_H__
#define __VERTEX_OPTIMISER_H__

#include "Vertex.h"

class VertexOptimiser
{
public:
	static std::vector<float> PackSingleVertex(Vertex vertex_data);
};

#endif