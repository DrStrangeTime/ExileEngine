#ifndef _WAVEFRONT_LOADER_H__
#define _WAVEFRONT_LOADER_H__

#include "MeshData.h"
#include "VertexOptimiser.h"

/* A global class for loading and packing mesh data from Wavefront files */
class WavefrontLoader
{
private:
	static std::vector<std::string>		GetDataFromFile(const char* file_uri);
	static MeshData						PackMeshData(std::vector<std::string>& file_data);

public:
	static MeshData						LoadDataFromFile(const char* file_uri);
};

#endif