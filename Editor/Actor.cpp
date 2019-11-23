#include "Actor.h"

Actor::Actor()
{
	_name = "Actor";
	_active = false;
	_dynamic = false;
	_type = 0;
	_trans.p = glm::vec3(0.0f);
	_trans.r = glm::vec3(0.0f);
	_trans.s = glm::vec3(1.0f);
	_trans.m = glm::mat4(1.0f);

	MakeModel();
}

// Copy constructor
Actor::Actor(const Actor& x)
{
	_name = x._name;
	_active = x._active;
	_dynamic = x._dynamic;
	_type = x._type;
	_trans.p = x._trans.p;
	_trans.r = x._trans.r;
	_trans.s = x._trans.s;
	_trans.m = x._trans.m;

	MakeModel();
}

bool& Actor::IsActive()
{
	return _active;
}

bool& Actor::IsDynamic()
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

	ExLogErr("Failed to find component by name!");

	return nullptr;
}

std::shared_ptr<Actor> Actor::GetComponentByIndex(unsigned int x)
{
	if (x > _components.size() - 1)
	{
		ExLogErr("Component Index is out of bounds!");
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

void Actor::MakeModel()
{
	_trans.m = glm::scale(_trans.s) *	// Assign the position
		glm::rotate(glm::radians(_trans.r.z), glm::vec3(0.0f, 0.0f, 1.0f)) *		// Rotation Z
		glm::rotate(glm::radians(_trans.r.y), glm::vec3(0.0f, 1.0f, 0.0f)) *		// Rotation Y
		glm::rotate(glm::radians(_trans.r.x), glm::vec3(1.0f, 0.0f, 0.0f)) *		// Rotation X
		glm::translate(_trans.p);	// And the scale
}

void Actor::AddComponent(std::shared_ptr<Actor> x)
{
	_components.reserve(1);
	_components.emplace_back(x);
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

	ExLogErr("Failed to find component by name!");
}

void Actor::RemoveComponentByIndex(unsigned int x)
{
	if (x > _components.size() - 1)
	{
		ExLogErr("Component Index is out of bounds!");
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
