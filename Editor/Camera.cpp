#include "Camera.h"

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
	return _projection;
}
