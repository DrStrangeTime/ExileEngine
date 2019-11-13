#ifndef __DYNAMIC_BUFFER_OBJECT_H__
#define __DYNAMIC_BUFFER_OBJECT_H__

#include "VertexBufferObject.h"

class DynamicVertexBufferObject : public VertexBufferObject
{
public:
	DynamicVertexBufferObject(VertexData vertex_data);

	virtual void Create() override;
	virtual void Destroy() {}
	virtual void Bind() override;
};

#endif
