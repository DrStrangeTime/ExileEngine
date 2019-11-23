#ifndef __MESH_DATA_H__
#define __MESH_DATA_H__

#include "Vertex.h"
#include "OffsetData.h"

#define MAX_LODS			STATIC_CAST(uint32_t, 24)
#define MAX_MESH_GROUPS		STATIC_CAST(uint32_t, 16)

/* Data struct used for multiple material assignment */
struct MeshGroup {
	uint32_t	mat_id;
	OffsetData	offset;

	MeshGroup() : mat_id(0), offset(OffsetData()) {}
	MeshGroup(uint32_t m, OffsetData o) {
		mat_id = m;
		offset = o;
	}
};

/* Contains all information about a mesh structure */
struct MeshData
{
	uint32_t				num_lods;
	VertexData				vertex_data;
	std::vector<uint32_t>	index_data;
	std::vector<MeshGroup>	elements;

	MeshData() : num_lods(0), vertex_data(VertexData()) {}
	MeshData(uint32_t lods, VertexData& v, std::vector<uint32_t>& i, std::vector<MeshGroup>& g)
	{
		num_lods = lods;
		vertex_data = v;
		index_data = i;
		elements = g;
	}
};

#endif