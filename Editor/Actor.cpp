#include "Actor.h"

Actor::Actor()
{
	_trans = Transform::Data();
}

Actor::Actor(std::string n)
{
	_name = n;
	_trans = Transform::Data();
}

Actor::Actor(std::string n, glm::vec3 p, glm::vec3 r, glm::vec3 s)
{
	_name = n;
	_trans = Transform::Data();
}

Transform::Data& Actor::GetTransform()
{
	return _trans;
}

void Actor::SetTransform(Transform::Data x)
{
	_trans = x;
}