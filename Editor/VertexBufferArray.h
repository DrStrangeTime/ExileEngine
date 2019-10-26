#ifndef __VERTEX_BUFFER_ARRAY_H__
#define __VERTEX_BUFFER_ARRAY_H__

#include "Buffer.h"
#include "IndexBufferObject.h"
#include "VertexBufferObject.h"

class VertexBufferArray : public Buffer
{
private:
	uint16_t											_num_attribs;
	std::shared_ptr<IndexBufferObject>					_ibo;
	std::vector<std::shared_ptr<VertexBufferObject>>	_vbos;

public:
	VertexBufferArray(uint16_t num_attributes, std::vector<std::shared_ptr<VertexBufferObject>> vertex_buffer_objects, std::shared_ptr<IndexBufferObject> index_buffer_object);
	~VertexBufferArray();

	void Create() override;
	void Destroy() override;
	void Bind() override;

	uint16_t& GetNumAttributes();
	std::shared_ptr<IndexBufferObject>& GetIndexBuffer();
	std::vector<std::shared_ptr<VertexBufferObject>>& GetVertexBuffers();
};

#endif