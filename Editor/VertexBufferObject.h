#ifndef __VERTEX_BUFFER_OBJECT_H__
#define __VERTEX_BUFFER_OBJECT_H__

#include "Buffer.h"
#include "Vertex.h"

class VertexBufferObject : public Buffer
{
private:
	uint16_t	_num_vertex_elements;
	Vertex		_vertex_data;

public:
	VertexBufferObject(Vertex vertex_data);
	~VertexBufferObject();

	void Create() override;
	void Destroy() override;
	void Bind() override;

	Vertex& GetVertexData();
};

#endif