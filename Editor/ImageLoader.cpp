#include "ImageLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

/* Load almost any image format and store data to a texture struct */
TextureData ImageLoader::LoadDataFromFile(const char* uri)
{
	TextureData td;		// Resulting structure

	stbi_set_flip_vertically_on_load(true);		// Flip horrizontally for OpenGL only
	td.data = stbi_load(uri, &td.width, &td.height, &td.channels, 0);

#ifdef _DEBUG
	if (!td.data)
		ExCore::Logger::PrintErr("Failed to load texture file!");
#endif

	return td;
}
