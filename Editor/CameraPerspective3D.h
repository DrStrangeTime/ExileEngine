#ifndef __CAMERA_PERSPECTIVE_3D_H__
#define __CAMERA_PERSPECTIVE_3D_H__

#include "Camera.h"

/* Default 3D camera properties */
#define CAMERA_YAW					STATIC_CAST(float, 0.f)
#define CAMERA_PITCH				STATIC_CAST(float, 0.f)
#define CAMERA_PITCH_THRESHOLD		STATIC_CAST(float, 85.f)
#define CAMERA_FIELD_OF_VIEW		STATIC_CAST(float, 45.f)
#define CAMERA_LOOK_SENSITIVITY		STATIC_CAST(double, .1f)


/* Contains data for thresholding camera mechanics */
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

/* A three dimensional perspective camera */
class CameraPerspective3D : public Camera
{
private:
	float		_fov;

	float		_yaw;
	float		_pitch;
	float		_look_sensitivity_x;
	float		_look_sensitivity_y;

	glm::vec3	_front;
	glm::vec3	_right;
	glm::vec3	_up;

	SpringArm	_spring_arm;
	
public:
	CameraPerspective3D() : _fov(CAMERA_FIELD_OF_VIEW),
							_yaw(CAMERA_YAW),
							_pitch(CAMERA_PITCH),
							_look_sensitivity_x(CAMERA_LOOK_SENSITIVITY),
							_front(glm::vec3(.0f)), 
							_up(glm::vec3(.0f)), 
							_right(glm::vec3(.0f)), 
							_spring_arm(SpringArm()) {}

	CameraPerspective3D(const CameraPerspective3D& x);	// Copy constructor
	CameraPerspective3D(	uint32_t shader_program, 
							float near, 
							float far, 
							float fov, 
							float ratio, 
							float speed, 
							float look_sensitivity_x,
							float look_sensitivity_y,
							glm::vec3 position, 
							SpringArm spring_arm	);

	virtual ~CameraPerspective3D() {}

	virtual void	EventKey(int key, int scancode, int mods) override {}
	virtual void	EventMouseButton(int button, int action, int mods) override {}
	virtual void	EventMouseScroll(double xoffset, double yoffset) override {}
	
	virtual void	Update() override;
	virtual void	Render() override;

	float&			GetFov();
	float&			GetYaw();
	float&			GetPitch();
	float&			GetLookSensitivityX();
	float&			GetLookSensitivityY();
	glm::vec3&		GetFrontVector();
	glm::vec3&		GetRightVector();
	glm::vec3&		GetUpVector();

	inline void		SetFov(float value) { _fov = value; }
	inline void		SetYaw(float value) { _yaw = value; }
	inline void		SetPitch(float value) { _pitch = value; }
	inline void		SetLookSensitivityX(float value) { _look_sensitivity_x = value; }
	inline void		SetLookSensitivityY(float value) { _look_sensitivity_y = value; }
	inline void		SetFrontVector(glm::vec3 value) { _front = value; }
	inline void		SetRightVector(glm::vec3 value) { _right = value; }
	inline void		SetUpVector(glm::vec3 value) { _up = value; }

	virtual void	UpdateViewMatrix() override;
	virtual void	UpdateProjectionMatrix() override;
	virtual void	UpdateAspectRatio(float aspect) override;
	virtual void	UpdateLookVectors() override;
	virtual void	UpdateMouseRotation() override;
	virtual void	Move(float speed, glm::vec3 velocity) override;
};

#endif