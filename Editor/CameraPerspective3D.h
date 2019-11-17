#ifndef __CAMERA_PERSPECTIVE_3D_H__
#define __CAMERA_PERSPECTIVE_3D_H__

#include "Camera.h"

/* Default 3D camera properties */
#define CAMERA_YAW					STATIC_CAST(float, 0.f)
#define CAMERA_PITCH				STATIC_CAST(float, 0.f)
#define CAMERA_PITCH_THRESHOLD		STATIC_CAST(float, 85.f)
#define CAMERA_FIELD_OF_VIEW		STATIC_CAST(float, 45.f)
#define CAMERA_LOOK_SENSITIVITY		STATIC_CAST(glm::vec2, glm::vec2(1.f))


/* A structure containing data about the camera mechanics */
struct SpringArm
{
	float		pitch_threshold;
	glm::vec3	extension_offset;

	SpringArm() : pitch_threshold(CAMERA_PITCH_THRESHOLD), extension_offset(glm::vec3(0.f)) {}
	SpringArm(float pThreshold, glm::vec3 eOffset)
	{
		pitch_threshold = pThreshold;
		extension_offset = eOffset;
	}
};

/* A perspective camera in three dimension */
class CameraPerspective3D : public Camera
{
private:
	float		_fov;
	float		_yaw;
	float		_pitch;
	
	glm::vec2	_look_sensitivity;

	glm::vec3	_front;
	glm::vec3	_right;
	glm::vec3	_up;
	glm::vec3	_front_right;
	glm::vec3	_front_left;

	SpringArm	_spring_arm;
	
public:
	/* Default constructor */
	CameraPerspective3D() : _fov(CAMERA_FIELD_OF_VIEW),
							_yaw(CAMERA_YAW),
							_pitch(CAMERA_PITCH),
							_look_sensitivity(CAMERA_LOOK_SENSITIVITY),
							_front(glm::vec3(.0f)), 
							_front_right(glm::vec3(.0f)),
							_front_left(glm::vec3(.0f)),
							_up(glm::vec3(.0f)), 
							_right(glm::vec3(.0f)), 
							_spring_arm(SpringArm()) {}

#undef near
#undef far
	CameraPerspective3D(uint32_t shader_program, float near, float far, float fov, float ratio, float speed, float yaw, float pitch, glm::vec2 look_sensitivity, glm::vec3 position, SpringArm spring_arm)
	{
		_near = near;
		_far = far;
		_fov = fov;
		_ratio = ratio;
		_speed = speed;
		_yaw = yaw;
		_pitch = pitch;
		_look_sensitivity = look_sensitivity;
		_trans.p = position;
		_spring_arm = spring_arm;
		
		UpdateLookVectors();
		UpdateViewMatrix();
		UpdateProjectionMatrix();
	}
#define near
#define far



	virtual void	EventKey(int key, int scancode, int mods) override {}
	virtual void	EventMouseButton(int button, int action, int mods) override {}
	virtual void	EventMouseScroll(double xoffset, double yoffset) override {}

	virtual void	Update() override;
	virtual void	Render() override;

	virtual void	UpdateViewMatrix() override;
	virtual void	UpdateProjectionMatrix() override;
	virtual void	UpdateLookVectors() override;
};

#endif