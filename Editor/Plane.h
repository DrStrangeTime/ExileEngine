#ifndef __PLANE_H__
#define __PLANE_H__

#include "BinarySpacePartition.h"

#define PLANE_DIR_X		0x0
#define PLANE_DIR_Y		0x1
#define PLANE_DIR_Z		0x2

class Plane : public BinarySpacePartition
{
public:
	Plane(float x, float y, float z, uint16_t direction, float w, float h, uint32_t mat_id);

	virtual void	EventKey(int key, int scancode, int mods) {}
	virtual void	EventMouseButton(int button, int action, int mods) {}
	virtual void	EventMouseScroll(double xoffset, double yoffset) {}
	virtual void	Update() {}

	virtual void	Render() override;
};

#endif