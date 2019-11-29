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
	{
		data.reserve(1);
		data.emplace_back(temp_data);
	}

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
	Wavefront::WFObject			data;

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
			data.g[current_group].e[current_element].m = c;
			
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

/* Sort vertex data in index order to construct triangles */
Wavefront::WFObject Wavefront::SortFWData(Wavefront::WFObject& unsorted_data)
{
	Wavefront::WFObject		data;
	uint32_t				i_offset(0);
	uint32_t				i_size(0);

	for (unsigned i = 0; i < unsorted_data.g.size(); ++i)	// Groups
	{
		data.g.emplace_back(Wavefront::WFGroup());
		for (unsigned j = 0; j < unsorted_data.g[i].e.size(); ++j)	// Element
		{

			data.g[i].e.emplace_back(Wavefront::WFElement());
			for (unsigned k = 0; k < unsorted_data.g[i].e[j].f.size(); ++k)		// Face
			{
				data.g[i].e[j].f.emplace_back(Wavefront::WFFace());

				/* Assign vertices in index order */
				data.v.emplace_back(unsorted_data.v[unsorted_data.g[i].e[j].f[k].i[0] - 1]);
				data.vt.emplace_back(unsorted_data.vt[unsorted_data.g[i].e[j].f[k].i[1] - 1]);
				data.vn.emplace_back(unsorted_data.vn[unsorted_data.g[i].e[j].f[k].i[2] - 1]);

				data.v.emplace_back(unsorted_data.v[unsorted_data.g[i].e[j].f[k].i[3] - 1]);
				data.vt.emplace_back(unsorted_data.vt[unsorted_data.g[i].e[j].f[k].i[4] - 1]);
				data.vn.emplace_back(unsorted_data.vn[unsorted_data.g[i].e[j].f[k].i[5] - 1]);

				data.v.emplace_back(unsorted_data.v[unsorted_data.g[i].e[j].f[k].i[6] - 1]);
				data.vt.emplace_back(unsorted_data.vt[unsorted_data.g[i].e[j].f[k].i[7] - 1]);
				data.vn.emplace_back(unsorted_data.vn[unsorted_data.g[i].e[j].f[k].i[8] - 1]);

				/* Assign index data */
				data.g[i].e[j].f[k].i[0] = unsorted_data.g[i].e[j].f[k].i[0];
				data.g[i].e[j].f[k].i[1] = unsorted_data.g[i].e[j].f[k].i[1];
				data.g[i].e[j].f[k].i[2] = unsorted_data.g[i].e[j].f[k].i[2];

				data.g[i].e[j].f[k].i[3] = unsorted_data.g[i].e[j].f[k].i[3];
				data.g[i].e[j].f[k].i[4] = unsorted_data.g[i].e[j].f[k].i[4];
				data.g[i].e[j].f[k].i[5] = unsorted_data.g[i].e[j].f[k].i[5];

				data.g[i].e[j].f[k].i[6] = unsorted_data.g[i].e[j].f[k].i[6];
				data.g[i].e[j].f[k].i[7] = unsorted_data.g[i].e[j].f[k].i[7];
				data.g[i].e[j].f[k].i[8] = unsorted_data.g[i].e[j].f[k].i[8];
			}

			/* Assign material data */
			data.g[i].e[j].m = unsorted_data.g[i].e[j].m;

			/* Assign offset data */
			i_offset = i_size;
			data.g[i].e[j].o.begin = i_offset;
			i_size += (STATIC_CAST(uint32_t, unsorted_data.g[i].e[j].f.size()) * 9);
			data.g[i].e[j].o.end = i_size;
		}

		/* Reset offset data */
		i_offset = 0;
		i_size = 0;
	}

	return data;
}

/* Convert WFData to a MeshData object */
MeshData Wavefront::ConvertToMeshData(Wavefront::WFObject& in_data, const bool unify_groups)
{
	// Convert data here...

	return MeshData();
}

/* The main function that loads a Wavefront file and returns a MeshData object */
MeshData Wavefront::LoadDataFromFile(const char* file_uri, const bool unify_groups)
{
	MeshData					data;

	/* Load and pack data */
	std::vector<std::string>	file_line_data = GetLineDataFromFile(file_uri);
	Wavefront::WFObject			obj_data = PackFWData(file_line_data);

	/* Sort and convert FWData to MeshData */
	Wavefront::WFObject		obj_data_sorted = SortFWData(obj_data);
	//data = ConvertToMeshData(obj_data_sorted, unify_groups);

	return data;
}