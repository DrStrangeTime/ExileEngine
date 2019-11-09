#include "Actor.h"


Actor::Actor()
{
	_name = "Actor";
	_active = false;
	_dynamic = false;
	_type = A_ACTOR;
	_trans.p = glm::vec3(0.0f);
	_trans.r = glm::vec3(0.0f);
	_trans.s = glm::vec3(1.0f);
	_trans.m = glm::mat4(1.0f);
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

uint32_t& Actor::GetType()
{
	return _type;
}

Transform::Data& Actor::GetTransform()
{
	return _trans;
}

std::shared_ptr<Actor> Actor::GetComponentByName(std::string x)
{
	
	for (unsigned int i = 0; i < _components.size(); ++i)
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

void Actor::SetType(uint32_t x)
{
	_type = x;
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
	for (unsigned int i = 0; i < _components.size(); ++i)
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

void Actor::EventKeyComponents(int key, int scancode, int mods)
{
	for (unsigned int i = 0; i < _components.size(); ++i)
		_components[i]->EventKey(key, scancode, mods);
}

void Actor::EventMouseButtonComponents(int button, int action, int mods)
{
	for (unsigned int i = 0; i < _components.size(); ++i)
		_components[i]->EventMouseButton(button, action, mods);
}

void Actor::EventMouseScrollComponents(double xoffset, double yoffset)
{
	for (unsigned int i = 0; i < _components.size(); ++i)
		_components[i]->EventMouseScroll(xoffset, yoffset);
}

void Actor::UpdateComponents()
{
	for (unsigned int i = 0; i < _components.size(); ++i)
		_components[i]->Update();
}

void Actor::RenderComponents()
{
	for (unsigned int i = 0; i < _components.size(); ++i)
		_components[i]->Render();
}