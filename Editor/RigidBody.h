#include "Actor.h"

class RigidBody : public Actor
{
private:
	float		_speed;
	float		_mass;
	float		_gravity;
	float		_friction;
	float		_bounce;
	glm::vec3	_velocity;

public:
	RigidBody();
	RigidBody(std::string n);
	RigidBody(std::string n,	glm::vec3 position,
								glm::vec3 rotation,
								float gravity,
								float mass,
								float friction,
								float bounce,
								bool active);
	float& GetSpeed();
	float& GetMass();
	float& GetGravity();
	float& GetFriction();
	float& GetBounce();
	glm::vec3& GetVelocity();

	void Event() override;
	void Update() override;
	void Render() override;

	void SimulatePhysics();

	void SetSpeed(float x);
	void SetMass(float x);
	void SetGravity(float x);
	void SetFriction(float x);
	void SetBounce(float x);
	void SetVelocity(glm::vec3 x);
};