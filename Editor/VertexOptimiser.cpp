#include "VertexOptimiser.h"

std::vector<float> VertexOptimiser::PackSingleVertex(VertexData& vertex_data)
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
			opt_vertex_data.reserve(1);
			opt_vertex_data.emplace_back(vertex_data.vertexElements[attrib_index].data[id]);
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

VertexElement VertexOptimiser::PackTangents(std::vector<uint32_t>& indices, VertexElement& uvs)
{
	VertexElement tangents;

	//for (unsigned int i = 0; i < vd.indices.size(); i += 3)	// For each triangle...
	//{
	//	unsigned int i_0 = vd.indices[i];	// Get index offset of 0
	//	unsigned int i_1 = vd.indices[i + 1];	// Get index offset of 1
	//	unsigned int i_2 = vd.indices[i + 2];	// Get index offset of 2

	//	glm::vec3 edge_0 = vd.positions[i_1] - vd.positions[i_0];	// Calculate first edge
	//	glm::vec3 edge_1 = vd.positions[i_2] - vd.positions[i_0];	// Calculate second edge

	//	float delta_u_0 = vd.texcoords[i_1].x - vd.texcoords[i_0].x;	// Calculate u 0 with texcoord x
	//	float delta_v_0 = vd.texcoords[i_1].y - vd.texcoords[i_0].y;	// Calculate v 0 with texcoord y
	//	float delta_u_1 = vd.texcoords[i_2].x - vd.texcoords[i_0].x;	// Calculate u 1 with texcoord x
	//	float delta_v_1 = vd.texcoords[i_2].y - vd.texcoords[i_0].y;	// Calculate v 1 with texcoord y

	//	float f = 1.0f / (delta_u_0 * delta_v_1 - delta_u_1 * delta_v_0);	// Calculate fraction

	//	glm::vec3 t;	// Temp tangent variable

	//	t.x = f * (delta_v_1 * edge_0.x - delta_v_0 * edge_1.x);	// Calculate tangent x
	//	t.y = f * (delta_v_1 * edge_0.y - delta_v_0 * edge_1.y);	// Calculate tangent y
	//	t.z = f * (delta_v_1 * edge_0.z - delta_v_0 * edge_1.z);	// Calculate tangent z

	//	vd.tangents[i_0] += glm::normalize(t);	// Assign tangent for point 0 + i
	//	vd.tangents[i_1] += glm::normalize(t);	// Assign tangent for point 1 + i
	//	vd.tangents[i_2] += glm::normalize(t);	// Assign tangent for point 2 + i

	//	vd.tangents[i_0] = glm::normalize(vd.tangents[i_0] - glm::dot(vd.tangents[i_0], vd.normals[i_0]) * vd.normals[i_0]); 	// Calculate tangent with normal 0
	//	vd.tangents[i_1] = glm::normalize(vd.tangents[i_1] - glm::dot(vd.tangents[i_1], vd.normals[i_1]) * vd.normals[i_1]); 	// Calculate tangent with normal 1
	//	vd.tangents[i_2] = glm::normalize(vd.tangents[i_2] - glm::dot(vd.tangents[i_2], vd.normals[i_2]) * vd.normals[i_2]); 	// Calculate tangent with normal 2
	//}

	return tangents;
}

VertexData VertexOptimiser::IndexVertexData(std::vector<uint32_t> indices, VertexData vertex_data)
{
	VertexData vd;
	return vd;
}