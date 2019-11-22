#ifndef __WORLD_H__
#define __WORLD_H__

#include "Map.h"

class World
{
public:
	static std::shared_ptr<Map>	map;
	//static std::unique_ptr<GUI> gui;
	//static std::unique_ptr<GameMode> gameMode;

	static void Initialise();
};

#endif