#ifndef __UINT64_VERTEX_BUFFER_OBJECT_H__
#define __UINT64_VERTEX_BUFFER_OBJECT_H__

#include "VertexBufferObject.h"

class Uint64VertexBufferObject : public VertexBufferObject
{
private:
	std::vector<GLuint64> _vertex_data;

public:
	Uint64VertexBufferObject(std::vector<GLuint64>& vertex_data, uint32_t location_offset);

	virtual void Create() override;
	virtual void Destroy() {}
	virtual void Bind() override;
};

#endif