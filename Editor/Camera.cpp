#include "Camera.h"

uint16_t& Camera::GetCameraType()
{
	return _cam_type;
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

glm::mat4& Camera::GetViewMatrix()
{
	return _view;
}

glm::mat4& Camera::GetProjectionMatrix()
{
	return _projection;
}
