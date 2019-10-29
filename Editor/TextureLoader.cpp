#include "TextureLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


TextureData TextureLoader::LoadImageDataFromFile(const char* uri)
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

uint32_t TextureLoader::LoadTexture2D(const char* uri)
{
	uint32_t tex_id = 0;
	TextureData td = LoadImageDataFromFile(uri);

#ifdef _DEBUG
	if (td.data == NULL)
	{
		ExCore::Logger::PrintErr("Failed to generate texture!");
		return 0;
	}
#endif

	glGenTextures(1, &tex_id);
	glBindTexture(GL_TEXTURE_2D, tex_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, td.width, td.height, 0, GL_RGB, GL_UNSIGNED_BYTE, td.data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(td.data);

	return tex_id;
}
