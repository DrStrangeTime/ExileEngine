#ifndef __IMAGE_LOADER_H__
#define __IMAGE_LOADER_H__

#include "Headers.h"
#include "TextureData.h"

class ImageLoader
{
public:
	static TextureData LoadDataFromFile(const char* uri);
};

#endif