#ifndef __CAMERA_H__
#define __CAMERA_H__

#define CAMERA_2D				0x0
#define CAMERA_3D_PERSPECTIVE	0x1
#define CAMERA_3D_ORTHOGRAPHIC	0x2

#include "Actor.h"

/* This abstract class contains the interface of a basic camera setup */
class Camera : public Actor
{
protected:
	uint16_t	_camType;

	glm::mat4	_viewMatrix;
	glm::mat4	_projectionMatrix;

public:
	void Event() {}
	void Update(double delta) {}
	void Render() {}
		
	glm::mat4& GetViewMatrix();
	glm::mat4& GetProjectionMatrix();
	uint16_t& GetCameraType();

	void SetCameraType(uint16_t value);
	void SetViewMatrix(glm::mat4 value);
	void SetProjectionMatrix(glm::mat4 value);
};

#endif