#include "RigidBody.h"

RigidBody::RigidBody()
{
	_name = "RigidBody";
	_active = true;
	_dynamic = true;
	_speed = 1.0f;
	_mass = 1.0f;
	_gravity = -1.0f;
	_friction = 0.0f;
	_bounce = 0.1f;
	_velocity = glm::vec3(0.0f);
}

RigidBody::RigidBody(std::string n)
{
	_name = n;
	_active = true;
	_dynamic = true;
	_speed = 1.0f;
	_mass = 1.0f;
	_gravity = -1.0f;
	_friction = 0.0f;
	_bounce = 0.1f;
	_velocity = glm::vec3(0.0f);
}

RigidBody::RigidBody(std::string n, glm::vec3 position, glm::vec3 rotation, float gravity, float mass, float friction, float bounce, bool active)
{
	_name = n;
	_active = active;
	_dynamic = true;
	_mass = mass;
	_gravity = gravity;
	_friction = friction;
	_bounce = bounce;
	_speed = 1.0f;
	_velocity = glm::vec3(0.0f);
}

float& RigidBody::GetSpeed()
{
	return _speed;
}

float& RigidBody::GetMass()
{
	return _mass;
}

float& RigidBody::GetGravity()
{
	return _gravity;
}

float& RigidBody::GetFriction()
{
	return _friction;
}

float& RigidBody::GetBounce()
{
	return _bounce;
}

glm::vec3& RigidBody::GetVelocity()
{
	return _velocity;
}

void RigidBody::Event() {}
void RigidBody::Update()
{
	if (_active)
		SimulatePhysics();
}

void RigidBody::Render() {}

void RigidBody::SimulatePhysics()
{
	// Bullet physics simulation here...
}

void RigidBody::SetSpeed(float x)
{
	_speed = x;
}

void RigidBody::SetMass(float x)
{
	_mass = x;
}

void RigidBody::SetGravity(float x)
{
	_gravity = x;
}

void RigidBody::SetFriction(float x)
{
	_friction = x;
}

void RigidBody::SetBounce(float x)
{
	_bounce = x;
}

void RigidBody::SetVelocity(glm::vec3 x)
{
	_velocity = x;
}
