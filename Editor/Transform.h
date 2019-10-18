#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Headers.h"
#include <glm/gtx/transform.hpp>

class Transform
{
public:
	struct Data
	{
		glm::vec3 p;
		glm::vec3 r;
		glm::vec3 s;

		glm::mat4 m;

		Data() : p(glm::vec3(0.0f)), r(glm::vec3(0.0f)), s(glm::vec3(1.0f)), m(glm::mat4(0.0f)) {}
	};

	static void UpdateModel(Data& x)
	{
		x.m = glm::scale(x.m, glm::vec3(x.s));
		x.m = glm::rotate(x.m, x.r.x, glm::vec3(1.0f, 0.0f, 0.0f));
		x.m = glm::rotate(x.m, x.r.y, glm::vec3(0.0f, 1.0f, 0.0f));
		x.m = glm::rotate(x.m, x.r.z, glm::vec3(0.0f, 0.0f, 1.0f));
		x.m = glm::translate(x.m, glm::vec3(x.p));
	}

	static void Translate(Data& d, glm::vec3 v)
	{
		d.p = v;
		UpdateModel(d);
	}

	static void RotateLocalX()
	{

	}
};



#endif