#ifndef __VERTEX_OPTIMISER_H__
#define __VERTEX_OPTIMISER_H__

#include "Vertex.h"
#include "MeshData.h"

class VertexOptimiser
{
public:
	VertexOptimiser() = default;
	static std::vector<float>		PackSingleVertex(VertexData& vertex_data);
	static VertexElement			PackTangents(std::vector<uint32_t>& indices, VertexElement& uvs);
	static void						OptimiseVertexMeshData(MeshData& m);
};

#endif