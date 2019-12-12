#ifndef __STATIC_VERTEX_BUFFER_OBJECT_H__
#define __STATIC_VERTEX_BUFFER_OBJECT_H__

#include "VertexBufferObject.h"

class StaticVertexBufferObject : public VertexBufferObject
{
public:
	StaticVertexBufferObject(VertexData& vertex_data);

	virtual void Create() override;
	virtual void Destroy() {}
	virtual void Bind() override;

};

#endif