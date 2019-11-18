#include "CameraPerspective3D.h"

CameraPerspective3D::CameraPerspective3D(uint32_t shader_program, float near, float far, float fov, float ratio, float speed, float yaw, float pitch, glm::vec2 look_sensitivity, glm::vec3 position, SpringArm spring_arm)
{
	_active = true;
	_dynamic = true;
	_type = A_CAMERA;
	_name = "Perspective_cam";

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
	_front = WORLD_FRONT;
	_up = WORLD_UP;
	_right = WORLD_RIGHT;
	_world_up_vector = _up;

	UpdateMouseRotation(.0f, .0f);
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
	_yaw = x._yaw;
	_pitch = x._pitch;
	_look_sensitivity = x._look_sensitivity;
	_trans.p = x._trans.p;
	_spring_arm = x._spring_arm;
	_front = x._front;
	_up = x._up;
	_right = x._right;
	_world_up_vector = x._world_up_vector;

	UpdateMouseRotation(.0f, .0f);
	UpdateViewMatrix();
	UpdateProjectionMatrix();

	_u_view = x._u_view;
	_u_proj = x._u_proj;
}

void CameraPerspective3D::Update()
{
	ExCore::KeyInput::GetKeyState(GLFW_KEY_W) ? _local_dir |= LOOK_DIR_FRONT : _local_dir &= ~LOOK_DIR_FRONT;

	UpdateViewMatrix(); // TEMP
}

void CameraPerspective3D::Render()
{
	glUniformMatrix4fv(_u_proj, 1, GL_FALSE, value_ptr(_projection));
	glUniformMatrix4fv(_u_view, 1, GL_FALSE, value_ptr(_view));
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
	glm::vec3 calc_front;

	calc_front.x = cos(glm::radians(_yaw - 90.0f)) * cos(glm::radians(_pitch));
	calc_front.y = sin(glm::radians(_pitch));
	calc_front.z = sin(glm::radians(_yaw - 90.0f)) * cos(glm::radians(_pitch));

	_front = glm::normalize(calc_front);
	_right = glm::normalize(glm::cross(_front, _world_up_vector));
	_up = glm::normalize(glm::cross(_right, _front));
}

void CameraPerspective3D::Move(float speed, glm::vec3 velocity)
{
	_speed = speed;
	_velocity = velocity;

	_trans.p += (speed * glm::normalize(velocity));
}

void CameraPerspective3D::UpdateMouseRotation(double x_pos, double y_pos)
{
	x_pos *= _look_sensitivity.x;
	y_pos *= _look_sensitivity.y;

	_yaw += static_cast<float>(x_pos);
	_pitch += static_cast<float>(y_pos);

	if (_yaw > 360.0f)	_yaw = 0.0f;
	if (_yaw < 0.0f)	_yaw = 360.0f;

	if (_pitch > _spring_arm.pitch_threshold)	_pitch = _spring_arm.pitch_threshold;
	if (_pitch < -_spring_arm.pitch_threshold)	_pitch = -_spring_arm.pitch_threshold;
	
	UpdateLookVectors();
}