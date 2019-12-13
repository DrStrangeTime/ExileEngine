#ifndef __VERTEX_BUFFER_OBJECT_H__
#define __VERTEX_BUFFER_OBJECT_H__

#define STATIC_DRAW		0x0
#define DYNAMIC_DRAW	0x1

#include "Buffer.h"
#include "VertexOptimiser.h"

class VertexBufferObject : public Buffer
{
protected:
	int 				_draw_type;
	uint16_t			_num_vertex_elements;
	uint32_t			_location_offset;

public:
	VertexBufferObject() : _draw_type(GL_STATIC_DRAW) ,_num_vertex_elements(0) {}
	virtual ~VertexBufferObject();

	virtual void Create() override {}
	virtual void Destroy() override;
	virtual void Bind() override;
};

#endif