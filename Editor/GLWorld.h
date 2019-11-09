#ifndef __GL_WORLD_H__
#define __GL_WORLD_H__

#include "Map.h"

class GLWorld
{
public:
	static std::unique_ptr<Map>	map;
	//static std::unique_ptr<GUI> gui;
	//static std::unique_ptr<GameMode> gameMode;

	static void Initialise();
};

#endif