#include "VertexOptimiser.h"

std::vector<float> VertexOptimiser::PackSingleVertex(Vertex vertex_data)
{
	std::vector<float> opt_vertex_data;

	bool finished = false;
	auto vertex_size = vertex_data.vertexElements[0].data.size() / vertex_data.vertexElements[0].componentSize;
	auto attrib_size = vertex_data.vertexElements.size();
	auto attrib_index = 0;
	auto vertex_index = 0;

	while (!finished)
	{
		// Get the current component size
		auto comp_size = vertex_data.vertexElements[attrib_index].componentSize;

		// Add new set of data from a vertex element
		for (auto i = 0; i < comp_size; ++i) // Iterate through each vertex component
		{
			auto id = i + (vertex_index * comp_size);
			opt_vertex_data.push_back(vertex_data.vertexElements[attrib_index].data[id]);
		}

		// Go to next attrib
		attrib_index++;

		// Rotate attrib index
		if (attrib_index > vertex_data.vertexElements.size() - 1)
		{
			attrib_index = 0;
			vertex_index++;
		}

		// Check for last vertex
		if (vertex_index > vertex_size - 1)
			finished = true;
	}

	return opt_vertex_data;
}
