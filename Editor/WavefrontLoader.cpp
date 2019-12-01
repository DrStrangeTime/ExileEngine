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
Wavefront::WFObject Wavefront::PackFWData(const std::vector<std::string>& line_data)
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
				data.g[current_group].e[current_element].m = STATIC_CAST(uint32_t, (mat_id_names.size() - 1));
				mat_name_exists = false;
			}

			break;

		case 'f':	// FACE
			uint32_t vi[9];

			sscanf_s((&line_data[i])[0].c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &vi[0], &vi[1], &vi[2], &vi[3], &vi[4], &vi[5], &vi[6], &vi[7], &vi[8]);
			data.g[current_group].e[current_element].f.push_back({ vi[0], vi[1], vi[2], vi[3], vi[4], vi[5], vi[6], vi[7], vi[8] });

			break;
		}
	}

	return data;
}

/* Convert WFData to a MeshData object */
MeshData Wavefront::ConvertToMeshData(Wavefront::WFObject& in_data)
{
	MeshData	data;
	uint32_t	current_element(0);
	uint32_t	current_chunk(0);
	uint32_t	i_offset(0);
	uint32_t	i_size(0);

	for (unsigned i = 0; i < in_data.g.size(); ++i)		// Object (Collapse all fw groups)
	{
		current_element = 0;

		data.vertex_data.vertexElements.reserve(VERTICES_PER_FACE);

		data.vertex_data.vertexElements.emplace_back(VERTICES_PER_FACE);
		data.vertex_data.vertexElements.emplace_back(VERTICES_PER_FACE);
		data.vertex_data.vertexElements.emplace_back(VERTICES_PER_FACE);

		data.chunks.emplace_back();

		for (unsigned j = 0; j < in_data.g[i].e.size(); ++j)	// Chunk
		{
			if (current_element != 0)
				data.chunks.emplace_back();

			for (unsigned k = 0; k < in_data.g[i].e[j].f.size(); ++k)		// Triangle
			{
				/* Transfer vertex data from FWObject to MeshData */
				data.vertex_data.vertexElements[0].data.reserve(INDICES_PER_FACE);
				data.vertex_data.vertexElements[1].data.reserve(INDICES_PER_FACE);
				data.vertex_data.vertexElements[2].data.reserve(INDICES_PER_FACE);

				// Transfer vertex data
				for (unsigned n = VERTICES_PER_FACE; n < INDICES_PER_FACE; n += VERTICES_PER_FACE)
				{
					data.vertex_data.vertexElements[0].data.emplace_back(in_data.v[in_data.g[i].e[j].f[k].i[n - 3] - 1].x);
					data.vertex_data.vertexElements[0].data.emplace_back(in_data.v[in_data.g[i].e[j].f[k].i[n - 3] - 1].y);
					data.vertex_data.vertexElements[0].data.emplace_back(in_data.v[in_data.g[i].e[j].f[k].i[n - 3] - 1].z);
					data.vertex_data.vertexElements[1].data.emplace_back(in_data.vt[in_data.g[i].e[j].f[k].i[n - 2] - 1].x);
					data.vertex_data.vertexElements[1].data.emplace_back(in_data.vt[in_data.g[i].e[j].f[k].i[n - 2] - 1].y);
					data.vertex_data.vertexElements[1].data.emplace_back(in_data.vt[in_data.g[i].e[j].f[k].i[n - 2] - 1].z);
					data.vertex_data.vertexElements[2].data.emplace_back(in_data.vn[in_data.g[i].e[j].f[k].i[n - 1] - 1].x);
					data.vertex_data.vertexElements[2].data.emplace_back(in_data.vn[in_data.g[i].e[j].f[k].i[n - 1] - 1].y);
					data.vertex_data.vertexElements[2].data.emplace_back(in_data.vn[in_data.g[i].e[j].f[k].i[n - 1] - 1].z);
				}

				/* Transfer index data */
				data.index_data.reserve(INDICES_PER_FACE);
				for (unsigned n = 0; n < INDICES_PER_FACE; ++n)
					data.index_data.emplace_back(in_data.g[i].e[j].f[k].i[n]);
			}

			/* Assign chunk data */
			i_offset = i_size;
			data.chunks[current_chunk].index_offset.begin = i_offset;
			i_size += (STATIC_CAST(uint32_t, in_data.g[i].e[j].f.size()) * 9);
			data.chunks[current_chunk].index_offset.end = i_size;
			data.chunks[current_chunk].mat_id = in_data.g[i].e[j].m;

			++current_chunk;
			++current_element;
		}
	}

	data.vertex_data.size = (STATIC_CAST(uint32_t, data.vertex_data.vertexElements[0].data.size()) / data.vertex_data.vertexElements[0].componentSize);
	data.vertex_data.stride = INDICES_PER_FACE;

	return data;
}

/* The main function that loads a Wavefront file and returns a MeshData object */
MeshData Wavefront::LoadDataFromFile(const char* file_uri)
{
	MeshData					data;

	/* Load and pack data */
	std::vector<std::string>	file_line_data = GetLineDataFromFile(file_uri);
	Wavefront::WFObject			obj_data = PackFWData(file_line_data);

	/* Sort, convert and optimise data */
	data = ConvertToMeshData(obj_data);

	return data;
}