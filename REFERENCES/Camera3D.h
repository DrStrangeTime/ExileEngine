#ifndef __CAMERA_H__
#define __CAMERA_H__

#define ORTHO			0x1		// Define an ortho mode
#define PERSPECTIVE		0x2		// Define a perspective mode

#include "Actor.h"		// Extend from our abstrct class
#include "Globals.h"	// Get access to width and height of viewport 
#include "Keyboard.h"	// Assign keycodes and states for our keyboard

// This will be our type of camera directions
enum CameraDirections
{
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	FRONT_RIGHT,
	FRONT_LEFT,
	BACK_RIGHT,
	BACK_LEFT
};

// This is our camera class for moving in Cartesian space
class Camera : public Actor
{
protected:
	float		_fov;	// Header/Feild of view
	float		_near;	// Near plane
	float		_far;	// Far plane
	float		_ratio;	// Ratio for perspective mode
	float		_pitch;	// Pitch rotation 
	float		_yaw;	// Yaw rotation
	float		_speed;		// Speed of movement

	int			_proj_type;		// Projection type (Ortho or Perspective)
	int			_current_look_vector;	// Tell us what look vector we're using

	unsigned int _u_view;	// The view matrix uniform
	unsigned int _u_proj;	// The projection matrix uniform

	glm::vec3	_front;		// Front vector
	glm::vec3	_front_right;	// Front right vector
	glm::vec3	_front_left;	// Front right vector
	glm::vec3	_back_right;	// Front right vector
	glm::vec3	_back_left;	// Front right vector
	glm::vec3	_up;		// Up vector
	glm::vec3	_right;		// Right vector 
	glm::vec3	_world_up;	// World orientation
	glm::vec3	_velocity;	// The velocity vector
	glm::vec3	_position_offset;	// The camera's position offset from player

	glm::mat4	_view;	// The view matrix
	glm::mat4	_proj;	// The projection matrix
	

public:
	bool		_looked;	// Check if the camera look vector has just rotated

	// Default constructor
	inline Camera() { _t = CAMERA; }

	// Initialise camera data
	inline void InitialiseCamera(unsigned int shader_program, glm::vec3 position, glm::vec3 position_offset, float fov, float speed, float sensitivity, float n, float f, float ratio)
	{
		_t = CAMERA;	// Set actor type

		_u_view = glGetUniformLocation(shader_program, "view");		// Locate our view uniform
		_u_proj = glGetUniformLocation(shader_program, "proj");		// Locate our proj uniform

		_front = glm::vec3(0.0f, 0.0f, -1.0f);	// Initialise the front vector
		_up = glm::vec3(0.0f, 1.0f, 0.0f);	// Initialise the up vector
		_world_up = _up;		// Assign world up to the up vector by default
		_velocity = _front;		// Assign our default velocity vector
		_current_look_vector = FRONT;	// By default we set the look vector to front
		_trans._pos = position - position_offset;		// Assign position
		_position_offset = position_offset;		// Assign position offset
		_fov = fov;		// Assign feild-of-view
		_near = n;	// Assign near plane
		_far = f;		// Assign far plane
		_ratio = ratio;	// Assign ratio
		_yaw = 0.0f;	// Set the yaw value
		_pitch = 0.0f;	// Set the pitch value
		_speed = speed;		// Set the speed value
		_looked = false;

		SetProjectionType(PERSPECTIVE);		// Assign proj type
		UpdateLookVectors();	// Update the current look vectors
	}

	inline int GetProjectionType() { return _proj_type; }	// Return the projection matrix type

	inline glm::mat4 GetViewMatrix() { return glm::lookAt(_trans._pos, _trans._pos + _front, _up); }	// Function for getting LookAt matrix
	inline glm::mat4 GetProjectionMatrix() { return _proj; }		// Function for getting projection matrix

	inline glm::vec3 &GetCamPosition() { return _trans._pos; }	// Return camera position
	inline glm::vec3 &GetPositionOffset() { return _position_offset; }	// Return the position offset
	inline glm::vec3 &GetFront() { return _front; }	// Return the front vector
	inline glm::vec3 &GetUp() { return _up; }	// Return the up vector
	inline glm::vec3 &GetRight() { return _right; }	// Return the right vector
	inline glm::vec3 &GetWorldUp() { return _world_up; }		// Return the world up vector
	inline glm::vec3 &GetVelocity() { return _velocity; }	// Return the velocity vector
	inline glm::vec3 GetCurrentLookVectorV()	// Get the currrent look vector
	{
		switch (_current_look_vector)	// Switch through different cases...
		{
		case FRONT:		// If current is FRONT... 
			return _front;	// return front vector
		case BACK:	// If current is BACK
			return -_front;		// return -front vector
		case LEFT:		// If current is LEFT
			return -_right;		// return -right vector
		case RIGHT:		// If current is RIGHT
			return _right;	// return right vector
		case FRONT_RIGHT:	// If current is RIGHT
			return _front_right;	// return front right vector
		case FRONT_LEFT:	// If current is RIGHT
			return _front_left;		// return front right vector
		case BACK_RIGHT:	// If current is RIGHT
			return _back_right;		// return front right vector
		case BACK_LEFT:	// If current is RIGHT
			return _back_left;		// return front right vector
		default:	// If current is something else...	
			break;	// Break from switch statement
		}

		return glm::vec3(-1.0f);	// Return -1 as no look vector can be distinguished
	}

	// Return the current direction at which the camera is moving
	inline int GetCurrentLookVector()
	{
		if (Keyboard::GetKey('W').down)		// Check front vector
		{
			if (Keyboard::GetKey('D').down)		// Check front right vector
			{
				_current_look_vector = FRONT_RIGHT;
			}
			else if (Keyboard::GetKey('A').down)	// Check front left vector
			{
				_current_look_vector = FRONT_LEFT;
			}
			else
				_current_look_vector = FRONT;
		}
		else if (Keyboard::GetKey('S').down)	// Check back vector
		{
			if (Keyboard::GetKey('D').down)		// Check back right vector
			{
				_current_look_vector = BACK_RIGHT;
			}
			else if (Keyboard::GetKey('A').down)	// Check back left vector
			{
				_current_look_vector = BACK_LEFT;
			}
			else
				_current_look_vector = BACK;
		}
		else if (Keyboard::GetKey('A').down)	// Check left vector
			_current_look_vector = LEFT;
		else if (Keyboard::GetKey('D').down)	// Check right vector
			_current_look_vector = RIGHT;
		else
			return -1;	// Otherwise return -1 for no input

		return _current_look_vector;	// Return the final result
	}

	inline bool ControlActive() { return (GetCurrentLookVector() != -1); }			// Check if key input has been pressed for moving camera

	inline float &GetFov() { return _fov; }	// Get our fov value
	inline float &GetNear() { return _near; }	// Get our near value
	inline float &GetFar() { return _far; }	// Get our far value
	inline float &GetRatio() { return _ratio; }	// Get our ratio value
	inline float &GetYaw() { return _yaw; }	// Get our _yaw value
	inline float &GetPitch() { return _pitch; }	// Get our _pitch value
	inline float &GetSpeed() { return _speed; }	// Get speed value

	inline void SetFov(float value) { _fov = value; }	// Assign a value to our fov
	inline void SetNear(float value) { _near = value; }		// Assign a value to our near
	inline void SetFar(float value) { _far = value; }	// Assign a value to our far
	inline void SetRatio(float value) { _ratio = value; }	// Assign a value to our ratio
	inline void SetYaw(float value) { _yaw = value; }	// Assign a value to our _yaw
	inline void SetPitch(float value) { _pitch = value; }	// Assign a value to our _pitch
	inline void SetSpeed(float value) { _speed = value; }	// Assign speed value
	inline void SetPositionOffset(glm::vec3 value) { _position_offset = value; }	// Assign position offset
	inline void SetFront(glm::vec3 value) { _front = value; }	// Assign a value to front
	inline void SetUp(glm::vec3 value) { _up = value; }	// Assign a value to up
	inline void SetRight(glm::vec3 value) { _right = value; }	// Assign a value to right
	inline void SetVelocity(glm::vec3 value) { _velocity = value; }		// Assign the velocity vector
	inline void SetCurrentLookVector(int value) { _current_look_vector = value; }	// Assign the current look vector

	inline void IncrementYaw(float value) { _yaw += value; }	// We can use this to interpolate the yaw value
	inline void IncrementPitch(float value) { _pitch += value; }	// We can use this to interpolate the pitch value
	inline void SetProjection(glm::mat4 value) { _proj = value; }		// Assign a value to the projection matrix

	// A function that can switch the projection type
	inline void SetProjectionType(unsigned int projection_type)
	{
		_proj_type = projection_type;	// Assign proj type

		if (projection_type == ORTHO)	// If the projection type is set to ORTHO...
			SetProjection(glm::ortho(0.0f, (float)_pd_width, 0.0f, (float)_pd_height));	// Assign the proj to an ortho projection type matrix
		else	// If the projection type is set to PROJECTION or otherwise...
			SetProjection(glm::perspective(_fov, _ratio, _near, _far));	// Assign the proj to a perspective projection type matrix
	}

	// A function that updates a camera's orientation vectors
	inline void UpdateLookVectors()
	{
		glm::vec3 front;	// This will be our normalised front vector

		front.x = cos(glm::radians(_yaw - 90.0f)) * cos(glm::radians(_pitch));	//	Set the X value in front vector for cosine yaw and pitch
		front.y = sin(glm::radians(_pitch));	// Set the Y value in front vector for sine pitch
		front.z = sin(glm::radians(_yaw - 90.0f)) * cos(glm::radians(_pitch));	// Set the Y value in front vector for sine yaw and cosine pitch

		_front = glm::normalize(front);		// Normalise the _front vector 
		_right = glm::normalize(glm::cross(_front, _world_up));		// Now use this normalised front vector to cross with the world_up vector in order to calculate the right vector
		_up = glm::normalize(glm::cross(_right, _front));	// Apply the same formula to get the up vector

		_front_right = (_front + _right) / 2.0f;	// Calculate front right vector
		_front_left = (_front - _right) / 2.0f;	// Calculate front left vector
		_back_right = (-_front + _right) / 2.0f;	// Calculate back right vector
		_back_left = (-_front - _right) / 2.0f;	// Calculate back left vector
	}

	// Proccess the mouse input for camera look rotation
	inline void ProccessMouseRotation(double x_offset, double y_offset, float sensitivity, bool constrain_pitch = true)
	{
		x_offset *= (sensitivity * MOUSE_SENSITIVITY);	// Attenuate the x_offset with our sensitivity value
		y_offset *= (sensitivity * MOUSE_SENSITIVITY);	// Attenuate the y_offset with our sensitivity value

		_yaw += (float)x_offset;	// Increment our camera _yaw with the mouse x_offset
		_pitch += (float)y_offset;	// Increment our camera _pitch with the mouse y_offset

		if (_yaw > 360.0f)	_yaw = 0.0f;	// Restrain yaw to 360 degree spin
		if (_yaw < 0.0f)	_yaw = 360.0f;	// Restrain yaw to 360 degree spin

		if (constrain_pitch)		// if pitch is constrained...
		{
			if (_pitch > 89.0f)		_pitch = 89.0f;		// Constrain up pitch
			if (_pitch < -89.0f)	_pitch = -89.0f;	// Constrain down pitch
		}

		UpdateLookVectors();	// Update our look vectors
	}

	// Update any changes made to one of the projection parameters
	inline void UpdateProjectionMatrix()
	{
		SetProjectionType(_proj_type);	// Set the projection to it's specific type
	}

	// Update view matrix
	inline void UpdateView()
	{
		_view = lookAt(_trans._pos, _trans._pos + _front, _up);		// Update the camera view position

		_view[3][0] = _view[3][0] - _position_offset.x;		// Apply position offset for x
		_view[3][1] = _view[3][1] - _position_offset.y;		// Apply position offset for y
		_view[3][2] = _view[3][2] - _position_offset.z;		// Apply position offset for z
	}

protected:

	// Pass uniform data to shaders
	inline void UpdateCamUniforms()
	{
		glUniformMatrix4fv(_u_view, 1, GL_FALSE, value_ptr(_view));		// Parse the view uniform data
		glUniformMatrix4fv(_u_proj, 1, GL_FALSE, value_ptr(_proj));		// Parse the projection uniform data
	}

public:
	// Virtual void functions
	inline virtual void Update(double &delta) {}
	inline virtual void Render() {}
};

#endif