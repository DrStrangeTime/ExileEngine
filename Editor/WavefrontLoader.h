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
	struct WFFace {
		uint32_t				i[INDICES_PER_FACE];		// Indices
	};

	struct WFElement {
		uint32_t				m;							// Mat ID
		std::vector<WFFace>		f;							// Faces

		WFElement() : m(0) {}
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
	Wavefront::WFObject			PackFWData(const std::vector<std::string>& line_data);
	MeshData					ConvertToMeshData(Wavefront::WFObject& in_data);

	MeshData					LoadDataFromFile(const char* file_uri);
#pragma endregion
}

#endif