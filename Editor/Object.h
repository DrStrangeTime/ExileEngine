#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <glm/glm.hpp>

class Object
{
protected:
	uint8_t		_type;

	glm::vec3	_pos;
	glm::vec3	_rot;
	glm::vec3	_sca;

public:
	virtual void Update() = 0;
	virtual void Render() = 0;
};

#endif