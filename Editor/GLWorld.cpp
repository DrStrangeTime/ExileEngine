#include "GLWorld.h"

void GLWorld::Initialise()
{
	map = std::make_unique<Map>("Untitled");
}

std::unique_ptr<Map>	GLWorld::map;