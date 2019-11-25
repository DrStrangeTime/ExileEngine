#ifndef _WAVEFRONT_LOADER_H__
#define _WAVEFRONT_LOADER_H__

#define VERTEX_OFFSET		0x3
#define INDICES_PER_FACE	0x9

#define MAX_TRI_COUNT	STATIC_CAST(uint32_t, 999999)

#include "MeshData.h"
#include "VertexOptimiser.h"


/* Wavefront header */
namespace Wavefront
{
#pragma region STRUCTS
	struct WFFace {
		uint32_t				i[9];		// Indices
	};

	struct WFElement {
		std::vector<WFFace>		f;			// Faces
	};

	struct WFGroup {
		std::vector<WFElement>	e;			// Elements
	};

	struct WFObject {
		std::vector<glm::vec3>	v;			// Positions
		std::vector<glm::vec3>	vn;			// Normals
		std::vector<glm::vec3>	vt;			// Texcoords

		std::vector<WFGroup>	g;			// Groups
	};
#pragma endregion


#pragma region FUNCTIONS
	static std::vector<std::string>		GetLineDataFromFile(const char* file_uri);
	static Wavefront::WFObject			PackFWData(std::vector<std::string>& line_data);
	static Wavefront::WFObject			SortFWData(Wavefront::WFObject& unsorted_data);
	static bool							FWDataExceedsMax(Wavefront::WFObject& fw_data);
	static MeshData						ConvertToMeshData(Wavefront::WFObject& in_data, bool unify_groups);

	static MeshData						LoadDataFromFile(const char* file_uri, bool unify_groups);
#pragma endregion
}

#endif