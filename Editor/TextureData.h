#ifndef __TEXTURE_DATA_H__
#define __TEXTURE_DATA_H__

/* This header file is used to store the essential 
   data for when loading a texture file */

struct TextureData {
	int				width;
	int				height;
	int				channels;
	unsigned char*	data;

	TextureData() : width(0),
					height(0),
					channels(0),
					data(nullptr) {}
};

#endif