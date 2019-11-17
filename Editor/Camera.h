#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Actor.h"

/* Camera types */
#define CAMERA_2D				0x0
#define CAMERA_3D_PERSPECTIVE	0x1
#define CAMERA_3D_ORTHOGRAPHIC	0x2

/* Look directions */
#define LOOK_DIR_FRONT			0x0
#define LOOK_DIR_BACK			0x1
#define LOOK_DIR_LEFT			0x2
#define LOOK_DIR_RIGHT			0x3
#define LOOK_DIR_FRONT_RIGHT	0x4
#define LOOK_DIR_FRONT_LEFT		0x5
#define LOOK_DIR_BACK_RIGHT		0x6
#define LOOK_DIR_BACK_LEFT		0x7


/* Base abstract class containing the main interface for each unique camera type */
class Camera : public Actor
{
protected:
	uint16_t	_cam_type;
	float		_near;
	float		_far;
	float		_ratio;
	float		_speed;
	glm::mat4	_view;
	glm::mat4	_projection;

	/* Uniform data */ 
	uint32_t	_u_view;
	uint32_t	_u_proj;

public:
	Camera() :	_cam_type(0),
				_near(.0f), 
				_far(.0f), 
				_ratio(.0f), 
				_speed(.0f), 
				_view(glm::mat4(1.0f)), 
				_projection(glm::mat4(1.0f)),
				_u_view(0),
				_u_proj(0) {}


	virtual void	EventKey(int key, int scancode, int mods) override {}
	virtual void	EventMouseButton(int button, int action, int mods) override {}
	virtual void	EventMouseScroll(double xoffset, double yoffset) override {}

	virtual void	Update() override {}
	virtual void	Render() override {}

	uint16_t&		GetCameraType();
	float&			GetNear();
	float&			GetFar();
	float&			GetRatio();
	float&			GetSpeed();
	glm::mat4&		GetViewMatrix();
	glm::mat4&		GetProjectionMatrix();

	inline void		SetCameraType(uint16_t value) { _cam_type = value; }
	inline void		SetNear(float value) { _near = value; }
	inline void		SetFar(float value) { _far = value; }
	inline void		SetRatio(float value) { _ratio = value; }
	inline void		SetSpeed(float value) { _speed = value; }
	inline void		SetViewMatrix(glm::mat4 value) { _view = value; }
	inline void		SetProjectionMatrix(glm::mat4 value) { _projection = value; }
};

#endif