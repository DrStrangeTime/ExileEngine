#ifndef __TEXTURE_LOADER_H__
#define __TEXTURE_LOADER_H__

#include "Headers.h"
#include "TextureData.h"


class TextureLoader
{
private:

public:
	static TextureData LoadImageDataFromFile(const char* uri);

	static uint32_t LoadTexture2D(const char* uri);
	//static uint32_t LoadTextureCubemap2D(const char* uri);
	//static uint32_t LoadTextureHdri2D(const char* uri);
	//static uint32_t LoadTexturePolar2D(const char* uri);
};

#endif

