#ifndef _WAVEFRONT_LOADER_H__
#define _WAVEFRONT_LOADER_H__

#define VERTICES_PER_FACE	STATIC_CAST(unsigned, 3)
#define INDICES_PER_FACE	STATIC_CAST(unsigned, 9)

#include "MeshData.h"
#include "VertexOptimiser.h"

/* Wavefront header */
namespace Wavefront
{

#pragma region STRUCTS
	struct WFElement {
		uint32_t				m;							// Mat ID
		std::vector<uint32_t>	i;							// Indices

		WFElement() : m(0) {}
		WFElement(uint32_t m_id) : m(m_id) {}
	};

	struct WFGroup {
		std::vector<WFElement>	e;							// Elements
	};

	struct WFObject {
		std::vector<glm::vec3>	v;							// Positions
		std::vector<glm::vec3>	vn;							// Normals
		std::vector<glm::vec3>	vt;							// Texcoords

		std::vector<WFGroup>	g;							// Groups
	};
#pragma endregion


#pragma region FUNCTIONS
	std::vector<std::string>	GetLineDataFromFile(const char* file_uri);
	Wavefront::WFObject			GetFWData(const std::vector<std::string>& line_data);
	std::vector<PackedVertex>	IndexVertexData(Wavefront::WFObject& in_data, std::vector<MeshChunk>& in_chunk_data);
	MeshData					LoadDataFromFile(const char* file_uri);
#pragma endregion
}

#endif