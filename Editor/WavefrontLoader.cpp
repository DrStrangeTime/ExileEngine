#include "WavefrontLoader.h"

std::vector<std::string> WavefrontLoader::GetDataFromFile(const char* file_uri)
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

MeshData WavefrontLoader::PackMeshData(std::vector<std::string>& file_data)
{
	if (file_data.empty())
	{
#ifdef _DEBUG
		ExLogErr("Failed to construct mesh data! This file is empty!");
#endif
		return MeshData();
	}

	MeshData	data;
	//bool		mat_id_exists(false);	
	//int		current_group(0);

	//for (unsigned int i = 0; i < file_data.size(); i++)	// Iterate through each file_data...
	//{
	//	switch ((file_data[i])[0])	// Check the value of the first character of each file_data
	//	{
	//	case 'v':	// If the character is a 'v'...
	//		float x, y, z;	// Create temp variables for vertices
	//		char chars[128];	// Create temp variable for character data
	//		if ((file_data[i])[1] == 'n')	// If the second character is 'n'...
	//		{
	//			sscanf_s((&file_data[i])[0].c_str(), "vn %f %f %f", &x, &y, &z);		// Scan this file_data and store the three floats to our temp variables
	//			obj.vn.push_back(glm::vec3(x, y, z));	// Record this data
	//		}
	//		if ((file_data[i])[1] == 't')	// If the second character is 't'...
	//		{
	//			sscanf_s((&file_data[i])[0].c_str(), "vt %f %f", &x, &y);	// Scan this file_data and store the two floats to our temp variables
	//			obj.vt.push_back(glm::vec3(x, -y, 0.0f));		// Record this data
	//		}
	//		else if ((file_data[i])[1] == ' ')	// If the second character is nothing...
	//		{
	//			sscanf_s((&file_data[i])[0].c_str(), "v %f %f %f", &x, &y, &z);	// Scan this file_data and store the three floats to our temp variables
	//			obj.v.push_back(glm::vec3(x, y, z));	// Record this data

	//			vcount++;
	//		}

	//		break;
	//	case 'o':	// if the character is a 'o'...
	//		sscanf_s((&file_data[i])[0].c_str(), "o %s", chars, 128);	// scan this file_data and store the chars to our temp variables
	//		out_obj.o = chars;	// Assign the object name to the obj data
	//		break;
	//	case 'u':
	//		sscanf_s((&file_data[i])[0].c_str(), "usemtl %s", chars, 128);	// scan this file_data and store the chars to our temp variables
	//		for (unsigned int j = 0; j < obj.u.size(); j++)	// Iterate through our mat names...
	//		{
	//			if (chars == obj.u[j])	// If the found id matches any existing ids...
	//			{
	//				mat_id_exists = true;	// Mat id already exists
	//				current_group = j;	// Set the current group id back to this mat id again
	//				break;
	//			}
	//		}
	//		if (!mat_id_exists)		// If the mat id doesn't already exist...
	//		{
	//			obj.u.push_back(chars);		// Add another mat to the mat string container
	//			obj.g.push_back(Group());	// Create a new group (obj element)	
	//			current_group = obj.g.size() - 1;	// Set the current group id to the group size
	//		}
	//		mat_id_exists = false;	// Set mat id exists to false ready for the next
	//		break;
	//	case 'f':	// If the character is a 'f'...
	//		unsigned int v_i[3], vn_i[3], vt_i[3];	// Create temp variables for encapsulating face data

	//		sscanf_s((&file_data[i])[0].c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &v_i[0], &vt_i[0], &vn_i[0], &v_i[1], &vt_i[1], &vn_i[1], &v_i[2], &vt_i[2], &vn_i[2]);		// Scan and consume the face data for each file_data

	//		for (unsigned k = 0; k < 3; k++)	// For each vertex...
	//		{
	//			obj.g[current_group].v_i.push_back(v_i[k]);		// Add a new index for vertex type 0
	//			obj.g[current_group].vt_i.push_back(vt_i[k]);	// Add a new index for vertex type 1
	//			obj.g[current_group].vn_i.push_back(vn_i[k]);	// Add a new index for vertex type 2
	//		}

	//		break;
	//	}
	//}

	//unsigned int offset = 0;	// This variable will be used to increment the offsets for each groups indices
	//for (unsigned int g = 0; g < obj.g.size(); g++)		// Iterate through the number of groups...
	//{
	//	out_obj.g.push_back(Group());	// Create a new group for our out_obj

	//	for (unsigned int i = 0; i < obj.g[g].v_i.size(); i++)	// Iterate through the number of vertex indices...
	//	{
	//		unsigned int v_i = obj.g[g].v_i[i];		// Assign a temp varaible to each vertex position's index
	//		unsigned int vt_i = obj.g[g].vt_i[i];	// Assign a temp varaible to each vertex texcoord's index
	//		unsigned int vn_i = obj.g[g].vn_i[i];	// Assign a temp varaible to each vertex normal's index

	//		glm::vec3 vertex = obj.v[v_i - 1];	// Get the desired position vertex value using our vertex indices
	//		glm::vec3 uv = obj.vt[vt_i - 1];	// Get the desired texcoord vertex value using our vertex indices
	//		glm::vec3 normal = obj.vn[vn_i - 1];	// Get the desired normal vertex value using our vertex indices

	//		out_obj.v.push_back(vertex);	// Add the indexed version of the vertex position value to our out_obj
	//		out_obj.vt.push_back(uv);	// Add the indexed version of the vertex texcoord value to our out_obj
	//		out_obj.vn.push_back(normal);	// Add the indexed version of the normal position value to our out_obj

	//		out_obj.g[g].v_i.push_back(obj.g[g].v_i[i]);	// Assign the indices from the input to output data
	//	}

	//	unsigned int g_index_count = out_obj.g[g].v_i.size();	// Get the index count for each group by getting the index size
	//	out_obj.g[g].from = offset;		// Set the starting index point of each group's offset
	//	out_obj.g[g].to = offset + g_index_count;	// Set the end index point of each group's offset + index size
	//	offset += g_index_count;	// Increment the offset by the last index size
	//}

	return data;
}

MeshData WavefrontLoader::LoadDataFromFile(const char* file_uri)
{
	std::vector<std::string>	file_data	= GetDataFromFile(file_uri);
	MeshData					data		= PackMeshData(file_data);

	if (data.elements.empty())
	{
#ifdef _DEBUG
		ExLogErr("NULL mesh elements detected!");
#endif
		return MeshData();
	}

	return data;
}
