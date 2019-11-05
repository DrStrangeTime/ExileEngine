#pragma once

#include "Map.h"

class World
{
private:
	std::vector<std::vector<Actor>> mapActors;

public:
	World();

	virtual void EventKey(int key, int scancode, int mods);
	virtual void EventMouseButton(int button, int action, int mods);
	virtual void EventMouseScroll(double xoffset, double yoffset);
	virtual void Update(double delta);
	virtual void Render();

	void LerpState(std::shared_ptr<Map> a, std::shared_ptr<Map> b)
	{

	}
};

