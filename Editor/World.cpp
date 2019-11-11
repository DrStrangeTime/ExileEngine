#include "World.h"

void World::Initialise()
{
	map = std::make_unique<Map>("Untitled");
}

std::unique_ptr<Map>	World::map;