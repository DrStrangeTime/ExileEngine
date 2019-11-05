#ifndef CAMERA_H
#define CAMERA_H

#include "Object.h"

class Camera : public object
{
private:
	CBfloat		_fov;
	CBfloat		_near;
	CBfloat		_far;
	CBfloat		_speed;
	Math::vec3	_front;
	Math::vec3	_up;
	Math::mat4	_projection;
	Math::mat4	_view;

	CBuint		_u_projection;
	CBuint		_u_view;

public:
	Camera(Shader* shader, Math::vec3 pos, float fov, float n, float f) : _speed(5.0f)
	{
		_model = Math::mat4::identity();
		_projection = Math::mat4::identity();
		_view = Math::mat4::identity();

		_position = pos;
		_fov = fov;
		_near = n;
		_far = f;
		_front = vec3(0.0f, 0.0f, -1.0);
		_up = vec3(0.0f, 1.0f, 0.0f);

		_u_projection = glGetUniformLocation(shader->_program, "projection");
		_u_view = glGetUniformLocation(shader->_program, "view");
		_u_model = glGetUniformLocation(shader->_program, "view_loc");

		_front.data[0] = (float)Math::radians(57.2958);
		_front.data[1] = (float)Math::radians(-57.2958);
	}

	~Camera() {}

	inline void forward(double delta)	{ _position.data[2] -= _speed * (float)delta; }
	inline void back(double delta)		{ _position.data[2] += _speed * (float)delta; }
	inline void left(double delta)		{ _position.data[0] -= _speed * (float)delta; }
	inline void right(double delta)		{ _position.data[0] += _speed * (float)delta; }
	inline void up(double delta)		{ _position.data[1] += _speed * (float)delta; }
	inline void down(double delta)		{ _position.data[1] -= _speed * (float)delta; }

	virtual void update(double delta)
	{
		_view = Math::lookat(_position, _position + _front, _up);
		_projection = Math::ortho(-1.0f  * (float)_width / (float)_height, 1.0f  * (float)_width / (float)_height, -1.0f, 1.0f,  -1000, 1000);
	}

	virtual void render()
	{		
		glUniformMatrix4fv(_u_view, 1, GL_FALSE, _view);
		glUniformMatrix4fv(_u_projection, 1, GL_FALSE, _projection);
		glUniform3f(_u_model, _position.data[0], _position.data[1], _position.data[2]);
	}
};

#endif