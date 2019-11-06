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
	virtual void EventKey(int key, int scancode, int mods) override {}
	virtual void EventMouseButton(int button, int action, int mods) override {}
	virtual void EventMouseScroll(double xoffset, double yoffset) override {}
	virtual void Update() override {}
	virtual void Render() override {}

	inline glm::mat4& GetViewMatrix() { return _viewMatrix; }
	inline glm::mat4& GetProjectionMatrix() { return _projectionMatrix; }
	inline uint16_t& GetCameraType() { return _camType; }

	void SetCameraType(uint16_t value) { _camType = value; }
	void SetViewMatrix(glm::mat4 value) { _viewMatrix = value; }
	void SetProjectionMatrix(glm::mat4 value) { _projectionMatrix = value; }
};

#endif