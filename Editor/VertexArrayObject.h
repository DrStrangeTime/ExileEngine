#ifndef __VERTEX_ARRAY_OBJECT_H__
#define __VERTEX_ARRAY_OBJECT_H__

#include "Buffer.h"
#include "IndexBufferObject.h"
#include "VertexBufferObject.h"

class VertexArrayObject : public Buffer
{
private:
	std::shared_ptr<IndexBufferObject>						_ibo;
	std::vector<std::shared_ptr<VertexBufferObject>>		_vbos;

public:
	VertexArrayObject() = default;
	VertexArrayObject(std::vector<std::shared_ptr<VertexBufferObject>>& vertex_buffer_objects, std::shared_ptr<IndexBufferObject>& index_buffer_object);
	~VertexArrayObject();

	void												Create() override;
	void												Destroy() override;
	void												Bind() override;
	
	std::shared_ptr<IndexBufferObject>&					GetIndexBuffer();
	std::vector<std::shared_ptr<VertexBufferObject>>&	GetVertexBuffers();
};

#endif