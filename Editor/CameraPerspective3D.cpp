#include "CameraPerspective3D.h"

CameraPerspective3D::CameraPerspective3D(uint32_t shader_program, float near, float far, float fov, float ratio, float speed, float look_sensitivity_x, float look_sensitivity_y, glm::vec3 position, SpringArm spring_arm)
{
	_active = false;
	_dynamic = true;
	_type = A_CAMERA;
	_name = "Perspective_cam";

	_near = near;
	_far = far;
	_fov = fov;
	_ratio = ratio;
	_speed = speed;
	_pitch = .0f;
	_yaw = .0f;
	_look_sensitivity_x = look_sensitivity_x;
	_look_sensitivity_y = look_sensitivity_y;
	_trans.p = position;
	_spring_arm = spring_arm;
	_front = WORLD_FRONT;
	_up = WORLD_UP;
	_right = WORLD_RIGHT;
	_world_up_vector = _up;
	
	UpdateViewMatrix();
	UpdateProjectionMatrix();

	_u_view = glGetUniformLocation(shader_program, "view");
	_u_proj = glGetUniformLocation(shader_program, "proj");
}

/* Copy constructor */
CameraPerspective3D::CameraPerspective3D(const CameraPerspective3D& x)
{
	_active = x._active;
	_dynamic = x._dynamic;
	_type = x._type;
	_name = x._name;

	_near = x._near;
	_far = x._far;
	_fov = x._fov;
	_ratio = x._ratio;
	_speed = x._speed;
	_look_sensitivity_x = x._look_sensitivity_x;
	_look_sensitivity_y = x._look_sensitivity_y;
	_trans.p = x._trans.p;
	_spring_arm = x._spring_arm;
	_front = x._front;
	_up = x._up;
	_right = x._right;
	_world_up_vector = x._world_up_vector;

	UpdateViewMatrix();
	UpdateProjectionMatrix();

	_u_view = x._u_view;
	_u_proj = x._u_proj;
}

void CameraPerspective3D::Update()
{
	ExCore::KeyInput::GetKeyState(GLFW_KEY_W) ? _local_dir |= LOOK_DIR_FRONT :	_local_dir &= ~LOOK_DIR_FRONT;
	ExCore::KeyInput::GetKeyState(GLFW_KEY_S) ? _local_dir |= LOOK_DIR_BACK :	_local_dir &= ~LOOK_DIR_BACK;
	ExCore::KeyInput::GetKeyState(GLFW_KEY_A) ? _local_dir |= LOOK_DIR_LEFT :	_local_dir &= ~LOOK_DIR_LEFT;
	ExCore::KeyInput::GetKeyState(GLFW_KEY_D) ? _local_dir |= LOOK_DIR_RIGHT :	_local_dir &= ~LOOK_DIR_RIGHT;

	// TEMP --------------------------------------------------
	if ((_local_dir & LOOK_DIR_FRONT) & LOOK_DIR_FRONT) Move(_speed, _front);
	if ((_local_dir & LOOK_DIR_BACK) & LOOK_DIR_BACK) Move(_speed, -_front);
	if ((_local_dir & LOOK_DIR_LEFT) & LOOK_DIR_LEFT) Move(_speed, -_right);
	if ((_local_dir & LOOK_DIR_RIGHT) & LOOK_DIR_RIGHT) Move(_speed, _right);
	// -------------------------------------------------------

	UpdateViewMatrix();
}

void CameraPerspective3D::Render()
{
	glUniformMatrix4fv(_u_proj, 1, GL_FALSE, value_ptr(_projection));
	glUniformMatrix4fv(_u_view, 1, GL_FALSE, value_ptr(_view));
}

float& CameraPerspective3D::GetFov()
{
	return _fov;
}

float& CameraPerspective3D::GetYaw()
{
	return _yaw;
}

float& CameraPerspective3D::GetPitch()
{
	return _pitch;
}

float& CameraPerspective3D::GetLookSensitivityX()
{
	return _look_sensitivity_x;
}

float& CameraPerspective3D::GetLookSensitivityY()
{
	return _look_sensitivity_y;
}

glm::vec3& CameraPerspective3D::GetFrontVector()
{
	return _front;
}

glm::vec3& CameraPerspective3D::GetRightVector()
{
	return _right;
}

glm::vec3& CameraPerspective3D::GetUpVector()
{
	return _up;
}

void CameraPerspective3D::UpdateViewMatrix()
{
	_view = glm::lookAt(_trans.p, _trans.p + _front, _up);

	_view[3][0] = _view[3][0] - _spring_arm.extension_offset.x;
	_view[3][1] = _view[3][1] - _spring_arm.extension_offset.y;
	_view[3][2] = _view[3][2] - _spring_arm.extension_offset.z;
}

void CameraPerspective3D::UpdateProjectionMatrix()
{
	_projection = glm::perspective(_fov, _ratio, _near, _far);
}

void CameraPerspective3D::UpdateAspectRatio(float aspect)
{
	_ratio = aspect;
	UpdateProjectionMatrix();
}

void CameraPerspective3D::UpdateLookVectors()
{
	glm::vec3 front;
	
	front.x = cos(ExToRadians(_yaw - 90.f)) * cos(ExToRadians(_pitch));
	front.y = sin(ExToRadians(_pitch));
	front.z = sin(ExToRadians(_yaw - 90.f)) * cos(ExToRadians(_pitch));

	_front = glm::normalize(front);
	_right = glm::normalize(glm::cross(_front, _world_up_vector));
	_up = glm::normalize(glm::cross(_right, _front));
}

void CameraPerspective3D::Move(float speed, glm::vec3 velocity)
{
	_speed = speed;
	_velocity = velocity;

	_trans.p += (speed * glm::normalize(velocity));
}

void CameraPerspective3D::UpdateMouseRotation()
{
	if (_first_mouse)
	{
		_last_x = STATIC_CAST(float, ExGetMouseX());
		_last_y = STATIC_CAST(float, ExGetMouseY());

		_first_mouse = false;
	}

	float xoffset = STATIC_CAST(float, ExGetMouseX()) - _last_x;
	float yoffset = _last_y - STATIC_CAST(float, ExGetMouseY());

	_last_x = STATIC_CAST(float, ExGetMouseX());
	_last_y = STATIC_CAST(float, ExGetMouseY());

	xoffset *= _look_sensitivity_x;
	yoffset *= _look_sensitivity_y;

	_yaw += xoffset;
	_pitch += yoffset;

	if (_yaw > 360.0f)	_yaw = 0.0f;
	if (_yaw < 0.0f)	_yaw = 360.0f;

	if (_pitch > _spring_arm.pitch_threshold)	_pitch = _spring_arm.pitch_threshold;
	if (_pitch < -_spring_arm.pitch_threshold)	_pitch = -_spring_arm.pitch_threshold;
	
	UpdateLookVectors();
}