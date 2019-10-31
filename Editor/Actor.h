#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Object.h"
#include "Transform.h"

/* The actor class defines the lowest level of a physical game component. 
   Each actor contains a dynamic list of child actor components, respectively. */

class Actor : public Object
{
protected:
	bool								_active;	// Is object active?
	bool								_dynamic;	// Is object movable?
	Transform::Data						_trans;
	std::vector<std::shared_ptr<Actor>> _components;	// Child actors

	void UpdateComponents(double delta);
	void RenderComponents();

public:
	Actor();
	Actor(std::string n);
	Actor(std::string n, glm::vec3 p, glm::vec3 r, glm::vec3 s);

	void Event() override {}
	void Update(double delta) override {}
	void Render() override {}

	bool& GetActive();
	bool& GetDynamic();
	Transform::Data& GetTransform();
	std::shared_ptr<Actor> GetComponentByName(std::string x);
	std::shared_ptr<Actor> GetComponentByIndex(unsigned int x);
	std::vector<std::shared_ptr<Actor>>& GetComponents();
	
	void SetActive(bool x);
	void SetDynamic(bool x);
	void SetTransform(Transform::Data x);

	void AddComponent(std::shared_ptr<Actor> x);
	void RemoveComponentByName(std::string x);
	void RemoveComponentByIndex(unsigned int x);

	operator Transform::Data() const
	{
		return _trans;
	}

	operator bool() const
	{
		return _active;
	}

	operator uint8_t() const
	{
		return _type;
	}

	operator std::string() const
	{
		return _name;
	}
};

#endif