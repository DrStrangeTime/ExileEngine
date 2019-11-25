#include "WavefrontLoader.h"

/* A special namespace for the wavefront header data structure system */
namespace Wavefront
{
	/* Open file and store each line to a vector list of strings */
	static std::vector<std::string> Wavefront::GetLineDataFromFile(const char* file_uri)
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
	static Wavefront::WFObject Wavefront::PackFWData(std::vector<std::string>& line_data)
	{
		if (line_data.empty())
		{
#ifdef _DEBUG
			ExLogErr("Failed to construct mesh data! This file is empty!");
#endif
			return Wavefront::WFObject();
		}

		int						current_group(0);
		bool					mat_id_exists(false);
		Wavefront::WFObject		data;

		// Loop through each line here...

		return data;
	}

	/* Sort vertex data in index order to construct triangles */
	static Wavefront::WFObject Wavefront::SortFWData(Wavefront::WFObject& unsorted_data)
	{
		return Wavefront::WFObject();
	}

	static bool Wavefront::FWDataExceedsMax(Wavefront::WFObject& fw_data)
	{
		uint64_t n_count(0);
		for (auto i = 0; i < fw_data.g.size(); ++i)
		{
			for (auto j = 0; j < fw_data.g[i].e.size(); ++j)
			{
				n_count += fw_data.g[i].e[j].f.size();

				if (n_count > MAX_TRI_COUNT)
				{
#ifdef _DEBUG
					ExLogErr("Failed to create MeshData from file! Data exceeds max N count!");
#endif
					return true;
				}
			}
		}

		return false;
	}

	/* Convert WFData to a MeshData object */
	static MeshData Wavefront::ConvertToMeshData(Wavefront::WFObject& in_data, bool unify_groups)
	{
		return MeshData();
	}

	/* The main function that loads a Wavefront file and returns a MeshData object */
	static MeshData Wavefront::LoadDataFromFile(const char* file_uri, bool unify_groups)
	{
		MeshData					data;

		/* Load and pack data */
		std::vector<std::string>	file_line_data = GetLineDataFromFile(file_uri);
		Wavefront::WFObject			obj_data = PackFWData(file_line_data);

		/* Analyse tri count before moving onto optimisation stage */
		if (!FWDataExceedsMax(obj_data))
		{
			/* Sort and convert FWData to MeshData */
			Wavefront::WFObject		obj_data_sorted = SortFWData(obj_data);
			data = ConvertToMeshData(obj_data_sorted, unify_groups);
		}

		return data;
	}
}
