#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Object.h"
#include "Transform.h"

/* The actor class defines the lowest level of a physical game component. 
   Each actor contains a dynamic list of child actor components, respectively. */

class Actor : public Object
{
protected:
	Transform::Data _trans;

public:
	Actor();
	Actor(std::string n);
	Actor(std::string n, glm::vec3 p, glm::vec3 r, glm::vec3 s);

	virtual void Update() const = 0;
	virtual void Event() const = 0;
	virtual void Render() const = 0;

	Transform::Data& GetTransform();
	void SetTransform(Transform::Data x);

	operator Transform::Data() const
	{
		return _trans;
	}
};

#endif