#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Actor.h"

#undef near
#undef far

/* Constant global variables */
constexpr glm::vec3	WORLD_FRONT = glm::vec3(0.f, 0.f, -1.f);
constexpr glm::vec3	WORLD_UP	= glm::vec3(0.f, 1.f, 0.f);
constexpr glm::vec3	WORLD_RIGHT = glm::vec3(1.f, 0.f, 0.f);

/* Camera types */
#define CAMERA_2D				0x0
#define CAMERA_3D_PERSPECTIVE	0x1
#define CAMERA_3D_ORTHOGRAPHIC	0x2

/* Look directions */
#define LOOK_DIR_FRONT			1
#define LOOK_DIR_BACK			2
#define LOOK_DIR_LEFT			4
#define LOOK_DIR_RIGHT			8
#define LOOK_DIR_FRONT_RIGHT	16
#define LOOK_DIR_FRONT_LEFT		32
#define LOOK_DIR_BACK_RIGHT		64
#define LOOK_DIR_BACK_LEFT		128
#define LOOK_DIR_UP				256
#define LOOK_DIR_DOWN			512
#define LOOK_DIR_UP_RIGHT		1024
#define LOOK_DIR_UP_LEFT		2048
#define LOOK_DIR_DOWN_RIGHT		4096
#define LOOK_DIR_DOWN_LEFT		8192

/* Camera default properties */
#define CAMERA_NEAR				STATIC_CAST(float, .1f)
#define CAMERA_FAR				STATIC_CAST(float, 1000.f)
#define CAMERA_SPEED			STATIC_CAST(float, 10.f)
#define CAMERA_RATIO			STATIC_CAST(float, 0.562)

/* Base abstract class containing the main interface for each unique camera type */
class Camera : public Actor
{
protected:
	uint16_t	_cam_type;
	uint32_t	_local_dir;
	float		_near;
	float		_far;
	float		_ratio;
	float		_speed;
	glm::vec3	_velocity;
	glm::vec3	_world_up_vector;
	glm::mat4	_view;
	glm::mat4	_projection;

	/* Uniform data */ 
	uint32_t	_u_view;
	uint32_t	_u_proj;

public:
	Camera() :	_cam_type(0),
				_local_dir(0),
				_near(CAMERA_NEAR),
				_far(CAMERA_FAR),
				_ratio(CAMERA_RATIO),
				_speed(CAMERA_SPEED),
				_velocity(glm::vec3(0.f)),
				_world_up_vector(WORLD_UP),
				_view(glm::mat4(1.0f)), 
				_projection(glm::mat4(1.0f)),
				_u_view(0),
				_u_proj(0) {}

	Camera(const Camera& x);	// Copy constructor

	virtual void	EventKey(int key, int scancode, int mods) = 0;
	virtual void	EventMouseButton(int button, int action, int mods) = 0;
	virtual void	EventMouseScroll(double xoffset, double yoffset) = 0;

	virtual void	Update() = 0;
	virtual void	Render() = 0;

	uint16_t&		GetCameraType();
	uint32_t&		GetLocalDirection();
	float&			GetNear();
	float&			GetFar();
	float&			GetRatio();
	float&			GetSpeed();
	glm::vec3&		GetVelocity();
	glm::vec3&		GetWorldUpVector();
	glm::mat4&		GetViewMatrix();
	glm::mat4&		GetProjectionMatrix();

	inline void		SetCameraType(uint16_t value) { _cam_type = value; }
	inline void		SetLocalDirection(uint32_t value) { _local_dir = value; }
	inline void		SetNear(float value) { _near = value; }
	inline void		SetFar(float value) { _far = value; }
	inline void		SetRatio(float value) { _ratio = value; }
	inline void		SetSpeed(float value) { _speed = value; }
	inline void		SetVelocity(glm::vec3 value) { _velocity = value; }
	inline void		SetWorldUpVector(glm::vec3 value) { _world_up_vector = value; }
	inline void		SetViewMatrix(glm::mat4 value) { _view = value; }
	inline void		SetProjectionMatrix(glm::mat4 value) { _projection = value; }

	virtual void	UpdateViewMatrix() = 0;
	virtual void	UpdateProjectionMatrix() = 0;
	virtual void	UpdateLookVectors() = 0;
	virtual void	Move(float speed, glm::vec3 velocity) = 0;
};

#endif