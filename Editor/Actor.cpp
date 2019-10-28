#include "Actor.h"


Actor::Actor()
{
	_name = "Actor";
	_active = false;
	_dynamic = false;
	Transform::MakeModel(_trans, _trans.m);
}

Actor::Actor(std::string n)
{
	_name = n;
	_active = false;
	_dynamic = false;
	Transform::MakeModel(_trans, _trans.m);
}

Actor::Actor(std::string n, glm::vec3 p, glm::vec3 r, glm::vec3 s)
{
	_name = n;
	_active = false;
	_dynamic = false;
	Transform::MakeModel(_trans, _trans.m);
}

bool& Actor::GetActive()
{
	return _active;
}

bool& Actor::GetDynamic()
{
	return _dynamic;
}

Transform::Data& Actor::GetTransform()
{
	return _trans;
}

std::shared_ptr<Actor> Actor::GetComponentByName(std::string x)
{
	
	for (unsigned int i = 0; i < _components.size(); i++)
	{
		std::string n = *_components[i];
		if (n == x)
			return _components[i];
	}

	exLogErr("Failed to find component by name!");

	return nullptr;
}

std::shared_ptr<Actor> Actor::GetComponentByIndex(unsigned int x)
{
	if (x > _components.size() - 1)
	{
		exLogErr("Component Index is out of bounds!");
		return nullptr;
	}

	return _components[x];
}

std::vector<std::shared_ptr<Actor>>& Actor::GetComponents()
{
	return _components;
}

void Actor::SetActive(bool x)
{
	_active = x;
}

void Actor::SetDynamic(bool x)
{
	_dynamic = x;
}

void Actor::SetTransform(Transform::Data x)
{
	_trans = x;
}

void Actor::AddComponent(std::shared_ptr<Actor> x)
{
	_components.push_back(x);
}

void Actor::RemoveComponentByName(std::string x)
{
	for (unsigned int i = 0; i < _components.size(); i++)
	{
		std::string n = *_components[i];
		if (n == x)
		{
			_components.erase(_components.begin() + i);
			return;
		}
	}

	exLogErr("Failed to find component by name!");
}

void Actor::RemoveComponentByIndex(unsigned int x)
{
	if (x > _components.size() - 1)
	{
		exLogErr("Component Index is out of bounds!");
		return;
	}

	_components.erase(_components.begin() + x);
}

void Actor::UpdateComponents()
{
	for (std::shared_ptr<Actor> c : _components)
	{
		c->Update();
	}
}

void Actor::RenderComponents()
{
	for (std::shared_ptr<Actor> c : _components)
		c->Render();
}