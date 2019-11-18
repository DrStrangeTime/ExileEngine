#ifndef __CUSTOM_ACTOR_H__
#define __CUSTOM_ACTOR_H__

#include "Actor.h"

class CustomActor : public Actor
{
public:
	CustomActor() = default;
	CustomActor(std::string n);
	CustomActor(std::string n, glm::vec3 p, glm::vec3 r, glm::vec3 s);

	virtual ~CustomActor() {}

	virtual void EventKey(int key, int scancode, int mods) override;
	virtual void EventMouseButton(int button, int action, int mods) override;
	virtual void EventMouseScroll(double xoffset, double yoffset) override;
	virtual void Update() override;
	virtual void Render() override;
};

#endif