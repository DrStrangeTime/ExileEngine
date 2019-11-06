#ifndef __ACTOR_H__
#define __ACTOR_H__

#define A_ACTOR				0	// DONE
#define A_SPRITE			1
#define A_STATIC_MESH		2
#define A_SKELETAL_MESH		3
#define A_LIGHT				4
#define A_RIGID_BODY		5
#define A_CAMERA			6	//
#define A_CLIP				7	
#define A_PARTICLE			8
#define A_PARTICLE_SYSTEM	9	
#define A_EVENT				10
#define A_ANIM_SEQUENCE		11
#define A_TRIGGER_VOLUME	12
#define A_BLOCK_VOLUME		13
#define A_POST_FX_VOLUME	14
#define A_PAWN				15	
#define A_CONTROLLER		16
#define A_PLAYER			17
#define A_PATH_NODE			18
#define A_PATH_NODE_SYSTEM	19
#define A_LERP_CONTROL		20
#define A_PROJECTILE		21
#define A_PROJECTOR			22
#define A_MESH_COLLIDER		23
#define A_BOX_COLLIDER		24
#define A_CAPSULE_COLLIDER	25
#define A_RADIAL_COLLIDER	26
#define A_MAP				27

#define NUM_ACTOR_TYPES		28

#include "Object.h"
#include "Transform.h"

/* The actor class defines the lowest level of a physical game component. 
   Each actor contains a dynamic list of child actor components, respectively. */
class Actor : public Object
{
protected:
	bool								_active;	// Is object active?
	bool								_dynamic;	// Is object movable?
	uint32_t							_type;		// Actor type
	Transform::Data						_trans;
	std::vector<std::shared_ptr<Actor>> _components;	// Child actors

	void EventKeyComponents(int key, int scancode, int mods);
	void EventMouseButtonComponents(int button, int action, int mods);
	void EventMouseScrollComponents(double xoffset, double yoffset);
	void UpdateComponents();
	void RenderComponents();

public:
	Actor();
	Actor(std::string n);
	Actor(std::string n, glm::vec3 p, glm::vec3 r, glm::vec3 s);

	virtual void EventKey(int key, int scancode, int mods) = 0;
	virtual void EventMouseButton(int button, int action, int mods) = 0;
	virtual void EventMouseScroll(double xoffset, double yoffset) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	bool& GetActive();
	bool& GetDynamic();
	uint32_t& GetType();
	Transform::Data& GetTransform();
	std::shared_ptr<Actor> GetComponentByName(std::string x);
	std::shared_ptr<Actor> GetComponentByIndex(unsigned int x);
	std::vector<std::shared_ptr<Actor>>& GetComponents();
	
	void SetActive(bool x);
	void SetDynamic(bool x);
	void SetType(uint32_t x);
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