#include "WavefrontLoader.h"

/* A special namespace for the wavefront header data structure system */
	/* Open file and store each line to a vector list of strings */
std::vector<std::string> Wavefront::GetLineDataFromFile(const char* file_uri)
{
	std::ifstream	file(file_uri);

	if (!file)
	{
#ifdef _DEBUG
		ExLogErr("Failed to load wavefront file! This file is invalid!");
#endif
		return std::vector<std::string>();
	}

	char						temp_data[256];
	std::vector<std::string>	data;
	while (file.getline(temp_data, 256))
		data.emplace_back(temp_data);

	return data;
}

/* Manipulate line data and assign values to a WFObject */
Wavefront::WFObject Wavefront::GetFWData(const std::vector<std::string>& line_data)
{
	if (line_data.empty())
	{
#ifdef _DEBUG
		ExLogErr("Failed to construct mesh data! This file is empty!");
#endif
		return Wavefront::WFObject();
	}

	int							current_group(-1);
	int							current_element(-1);
	bool						mat_name_exists(false);
	uint32_t					num_mats(0);
	std::string					c_str("");
	Wavefront::WFObject			data;
	std::vector<std::string>	mat_id_names;

	for (auto i = 0; i < line_data.size(); ++i)
	{
		switch ((line_data[i])[0])
		{
			char c[128];
		case 'g':	// GROUP
			sscanf_s((&line_data[i])[0].c_str(), "g %s", c, 128);
			if (strcmp(c, "default") != 0)
			{
				++current_group;
				data.g.emplace_back(Wavefront::WFGroup());
			}

			current_element = -1;

			break;

		case 'v':	// VERTEX

			glm::vec3 vec(glm::vec3(.0f));
			if ((line_data[i])[1] == 't')
			{
				sscanf_s((&line_data[i])[0].c_str(), "vt %f %f %f", &vec.x, &vec.y, &vec.z);
				data.vt.emplace_back(vec);
			}
			else if ((line_data[i])[1] == 'n')
			{
				sscanf_s((&line_data[i])[0].c_str(), "vn %f %f %f", &vec.x, &vec.y, &vec.z);
				data.vn.emplace_back(vec);
			}
			else
			{
				sscanf_s((&line_data[i])[0].c_str(), "v %f %f %f", &vec.x, &vec.y, &vec.z);
				data.v.emplace_back(vec);
			}

			break;

		case 'u':	// ELEMENT

			++current_element;
			data.g[current_group].e.emplace_back(Wavefront::WFElement());

			/* Assign material to current element */
			sscanf_s((&line_data[i])[0].c_str(), "usemtl %s", c, 128);
			c_str = c;
			for (auto j = 0; j < mat_id_names.size(); ++j)
			{
				if (c_str == mat_id_names[j])
				{
					data.g[current_group].e[current_element].m = j;
					mat_name_exists = true;
					break;
				}
			}
			
			if (!mat_name_exists)
			{
				mat_id_names.emplace_back(c_str);
				data.g[current_group].e[current_element].m = STATIC_CAST(uint32_t, mat_id_names.size() - 1);
				mat_name_exists = false;
			}

			mat_name_exists = false;

			break;

		case 'f':	// FACE
			uint32_t vi[9];

			sscanf_s((&line_data[i])[0].c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &vi[0], &vi[1], &vi[2], &vi[3], &vi[4], &vi[5], &vi[6], &vi[7], &vi[8]);

			if (current_element < 0)
			{
				++current_element;
				data.g[current_group].e.emplace_back(WFElement(0));
			}

			for (auto j = 0; j < INDICES_PER_FACE; ++j)
				data.g[current_group].e[current_element].i.emplace_back( vi[j]);

			break;
		}
	}

	

	return data;
}

/* Convert WFData to a MeshData object */
std::vector<PackedVertex> Wavefront::IndexVertexData(Wavefront::WFObject& in_data, std::vector<MeshChunk>& in_chunk_data)
{
	uint32_t					current_element(0);
	uint32_t					current_chunk(0);
	uint32_t					i_offset(0);
	uint32_t					i_size(0);
	std::vector<PackedVertex>	data;

	data.reserve(1);
	
	for (unsigned i = 0; i < in_data.g.size(); ++i)		// Group (Collapse all fw groups by default)
	{
		current_element = 0;

		in_chunk_data.emplace_back();

		for (unsigned j = 0; j < in_data.g[i].e.size(); ++j)	// Element
		{
			if (current_element != 0)
				in_chunk_data.emplace_back();

				// Transfer vertex data
			for (unsigned n = 0; n < in_data.g[i].e[current_element].i.size(); n += INDICES_PER_FACE)
			{
				data.emplace_back(PackedVertex({	glm::vec3(in_data.v[in_data.g[i].e[j].i[n + 0] - 1]),
													glm::vec3(in_data.vt[in_data.g[i].e[j].i[n + 1] - 1]),
													glm::vec3(in_data.vn[in_data.g[i].e[j].i[n + 2] - 1]) }));

				data.emplace_back(PackedVertex({	glm::vec3(in_data.v[in_data.g[i].e[j].i[n + 3] - 1]),
													glm::vec3(in_data.vt[in_data.g[i].e[j].i[n + 4] - 1]),
													glm::vec3(in_data.vn[in_data.g[i].e[j].i[n + 5] - 1]) }));

				data.emplace_back(PackedVertex({	glm::vec3(in_data.v[in_data.g[i].e[j].i[n + 6] - 1]),
													glm::vec3(in_data.vt[in_data.g[i].e[j].i[n + 7] - 1]),
													glm::vec3(in_data.vn[in_data.g[i].e[j].i[n + 8] - 1]) }));
			}

			/* Assign chunk data */

			
			i_offset = i_size;
			in_chunk_data[current_chunk].index_offset.begin = i_offset;
			i_size += (STATIC_CAST(uint32_t, in_data.g[i].e[j].i.size()) / VERTEX_ATTRIBS_PER_FACE);
			in_chunk_data[current_chunk].index_offset.end = i_size - i_offset;
			in_chunk_data[current_chunk].mat_id = in_data.g[i].e[j].m;

			++current_chunk; ++current_element;
		}
	}

	return data;
}

/* The main function that loads a Wavefront file and returns a MeshData object */
MeshData Wavefront::LoadDataFromFile(const char* file_uri)
{
	MeshData					mesh_data;

	/* Load and pack data */
	std::vector<std::string>	file_line_data = GetLineDataFromFile(file_uri);
	Wavefront::WFObject			obj_data = GetFWData(file_line_data);

	/* Sort and convert data */
	std::vector<PackedVertex>	packed_data;
	packed_data = IndexVertexData(obj_data, mesh_data.chunks);

	/* Optimise data */
	VertexOptimiser::OptimiseVertexMeshData(mesh_data, packed_data);


	// --------------------------- DEBUG ---------------------------
	//ExLogInfo("Index size: " + TO_STRING(mesh_data.index_data.size()));

	//ExLogArr(&mesh_data.index_data[0], mesh_data.index_data.size(), "INDICES");
	/*for (unsigned int i = 0; i < mesh_data.chunks.size(); ++i)
	{
		ExLogWar("Element 0 Chunk begin " + TO_STRING(i) + ": " +TO_STRING(mesh_data.chunks[i].index_offset.begin));
		ExLogWar("Element 0 Chunk end " + TO_STRING(i) + ": " + TO_STRING(mesh_data.chunks[i].index_offset.end));
	}*/

	return mesh_data;
}