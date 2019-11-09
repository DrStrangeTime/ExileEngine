#include "CustomActor.h"


CustomActor::CustomActor(std::string n)
{
	SetName(n);
}

CustomActor::CustomActor(std::string n, glm::vec3 p, glm::vec3 r, glm::vec3 s)
{
	SetName(n);
	
	_trans.p = p;
	_trans.r = r;
	_trans.s = s;

	_trans.m = glm::mat4(1.0f);

	Transform::MakeModel(_trans, _trans.m);
}

void CustomActor::EventKey(int key, int scancode, int mods)
{
	EventKeyComponents(key, scancode, mods);
}

void CustomActor::EventMouseButton(int button, int action, int mods)
{
	EventMouseButtonComponents(button, action, mods);
}

void CustomActor::EventMouseScroll(double xoffset, double yoffset)
{
	EventMouseScrollComponents(xoffset, yoffset);
}

void CustomActor::Update()
{
	UpdateComponents();
}

void CustomActor::Render()
{
	RenderComponents();
}
