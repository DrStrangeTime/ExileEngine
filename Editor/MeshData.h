#ifndef __MESH_DATA_H__
#define __MESH_DATA_H__

#include "Vertex.h"
#include "OffsetData.h"

/* Data struct that represnts a MeshElement's division in chunks using index offset values */
struct MeshChunk {
	uint32_t	mat_id;
	OffsetData	index_offset;

	MeshChunk() : mat_id(0), index_offset(OffsetData()) {}
	MeshChunk(uint32_t m, OffsetData o) {
		mat_id = m;
		index_offset = o;
	}
};

/* Data struct that represnts a unique mesh object */
struct MeshData {
	VertexData					vertex_data;
	std::vector<uint32_t>		index_data;
	std::vector<MeshChunk>		chunks;

	MeshData() = default;
	MeshData(VertexData& v, std::vector<uint32_t>& i, std::vector<MeshChunk>& c) {
		vertex_data = v;
		index_data = i;
		chunks = c;
	}
};

#endif