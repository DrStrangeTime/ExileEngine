#include "World.h"

void World::Initialise()
{
	map = std::make_shared<Map>("Untitled");
}

std::shared_ptr<Map>	World::map;