#ifndef __MAP_H__
#define __MAP_H__

#include "Actor.h"

class Map : public Actor
{
private:
	std::vector<Actor> actors;

public:
	Map();

	void EventKey(int key, int scancode, int mods);
	void EventMouseButton(int button, int action, int mods);
	void EventMouseScroll(double xoffset, double yoffset);
	void Update(double delta);
	void Render();
};

#endif