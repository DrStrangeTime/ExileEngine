#include "Camera.h"

/* Copy constructor */
Camera::Camera(const Camera& x)
{
	_cam_type = x._cam_type;
	_local_dir = x._local_dir;
	_near = x._near;
	_far = x._far;
	_ratio = x._ratio;
	_speed = x._speed;
	_velocity = x._velocity;
	_world_up_vector = x._world_up_vector;
	_view = x._view;
	_proj = x._proj;
	_u_view = x._u_view;
	_u_proj = x._u_proj;
}

uint16_t& Camera::GetCameraType()
{
	return _cam_type;
}

uint32_t& Camera::GetLocalDirection()
{
	return _local_dir;
}

float& Camera::GetNear()
{
	return _near;
}

float& Camera::GetFar()
{
	return _far;
}

float& Camera::GetRatio()
{
	return _ratio;
}

float& Camera::GetSpeed()
{
	return _speed;
}

glm::vec3& Camera::GetVelocity()
{
	return _velocity;
}

glm::vec3& Camera::GetWorldUpVector()
{
	return _world_up_vector;
}

glm::mat4& Camera::GetViewMatrix()
{
	return _view;
}

glm::mat4& Camera::GetProjectionMatrix()
{
	return _proj;
}
