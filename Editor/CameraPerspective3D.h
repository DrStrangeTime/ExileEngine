#ifndef __CAMERA_PERSPECTIVE_3D_H__
#define __CAMERA_PERSPECTIVE_3D_H__

#include "Camera.h"

#define DEFAULT_YAW_THRESHOLD	STATIC_CAST(float, 85.f)

/* A structure containing data about the camera mechanics */
struct SpringArm
{
	float		yaw_threshold;
	glm::vec3	ext_offset;

	SpringArm() : yaw_threshold(DEFAULT_YAW_THRESHOLD), ext_offset(glm::vec3(0.0f)) {}
	SpringArm(glm::vec3 eOffset, float yThreshold)
	{
		ext_offset = eOffset;
		yaw_threshold = yThreshold;
	}
};

/* A perspective camera in three dimension */
class CameraPerspective3D : public Camera
{
private:
	float	_fov;


public:

};

#endif