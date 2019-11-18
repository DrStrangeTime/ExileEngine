#ifndef __BINARY_SPACE_PARTITION_H__
#define __BINARY_SPACE_PARTITION_H__

#define BSP_PLANE			0x0
#define BSP_CUBE			0x1
#define BSP_CYLINDER		0x2
#define BSP_SPHERE			0x3

#define BSP_ADDITION		0x0
#define BSP_SUBTRACTION		0x1

#include "Actor.h"
#include "VertexArrayObject.h"
#include "StaticVertexBufferObject.h"

/* The base BSP class for arbitrary objects */
class BinarySpacePartition : public Actor
{
protected:
	uint16_t							_cull_mode;
	uint16_t							_arbitrary_type;

	uint32_t							_mat_id;
	uint32_t							_u_model;

	VertexData							_vertex_data;

	std::shared_ptr<VertexArrayObject>	_vertex_array_object;
	std::shared_ptr<VertexBufferObject>	_vertex_buffer_object;
	std::shared_ptr<IndexBufferObject>	_index_buffer_object;

	void								Inverse();

public:
	BinarySpacePartition() : _mat_id(0), _u_model(0), _cull_mode(0), _arbitrary_type(0) {}

	virtual ~BinarySpacePartition() {}

	VertexData&							GetVertexData();

	void								SetMatID(uint32_t value);

	virtual void						EventKey(int key, int scancode, int mods) = 0;
	virtual void						EventMouseButton(int button, int action, int mods) = 0;
	virtual void						EventMouseScroll(double xoffset, double yoffset) = 0;
	virtual void						Update() = 0;
	virtual void						Render() = 0;
};

#endif