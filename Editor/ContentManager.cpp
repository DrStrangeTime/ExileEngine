#include "ContentManager.h"

void ContentManager::Import(uint32_t import_type, const char* file, std::string name)
{
	switch (import_type)
	{
	case IMPORT_TEXTURE_TYPE_ALBEDO:
		break;
	case IMPORT_TEXTURE_TYPE_ROUGHNESS:
		break;
	case IMPORT_TEXTURE_TYPE_METALNESS:
		break;
	case IMPORT_TEXTURE_TYPE_NORMAL:
		break;
	case IMPORT_TEXTURE_TYPE_EMISSIVE:
		break;
	case IMPORT_TEXTURE_TYPE_CUBE:
		break;
	case IMPORT_MESH_TYPE_WAVEFRONT:
		break;
	case IMPORT_MESH_TYPE_FBX:
		break;
	case IMPORT_SKELETAL_TYPE_FBX:
		break;
	case IMPORT_ANIMATION_TYPE_FBX:
		break;
	case IMPORT_AUDIO_TYPE_WAV:
		break;
	default:
#ifdef _DEBUG
		ExCore::Logger::PrintErr("Failed to load content! Import type is invalid!");
#endif
		break;
	}
}

std::vector<Texture>						ContentManager::textures;
std::vector<Material>						ContentManager::materials;
std::shared_ptr<BinarySpacePartition>		ContentManager::bsps[4];