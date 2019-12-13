#ifndef __CONTENT_MANAGER_H__
#define __CONTENT_MANAGER_H__

// BSPs
#include "Plane.h"
// Textures
#include "Texture.h"
// Materials
#include "Material.h"

//#include "StaticMesh.h"
//#include "WavefrontLoader.h"

#define IMPORT_TEXTURE_TYPE_ALBEDO		0
#define IMPORT_TEXTURE_TYPE_ROUGHNESS	1
#define IMPORT_TEXTURE_TYPE_METALNESS	2
#define IMPORT_TEXTURE_TYPE_NORMAL		3
#define IMPORT_TEXTURE_TYPE_EMISSIVE	4
#define IMPORT_TEXTURE_TYPE_CUBE		5
#define IMPORT_MESH_TYPE_WAVEFRONT		6
#define IMPORT_MESH_TYPE_FBX			7
#define IMPORT_SKELETAL_TYPE_FBX		8
#define IMPORT_ANIMATION_TYPE_FBX		9
#define IMPORT_AUDIO_TYPE_WAV			10

/* This will store all of the unique content */
class ContentManager
{
public:
	static std::vector<Texture>							textures;
	static std::vector<Material>						materials;
	static std::shared_ptr<BinarySpacePartition>		bsps[4];
	//static std::vector<std::shared_ptr<StaticMesh>>	staticMeshes;

	static void Import(uint32_t import_type, const char* file, std::string name);
};

#endif