#ifndef __BATCH_VERTEX_BUFFER_OBJECT_H__
#define __BATCH_VERTEX_BUFFER_OBJECT_H__

#include "VertexBufferObject.h"

class BatchVertexBufferObject : public VertexBufferObject
{
public:
	BatchVertexBufferObject(VertexData vertex_data);

	virtual void Create() override;
	virtual void Destroy() {}
	virtual void Bind() override;
};

#endif
