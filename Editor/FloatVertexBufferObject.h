#ifndef __STATIC_VERTEX_BUFFER_OBJECT_H__
#define __FLOAT_VERTEX_BUFFER_OBJECT_H__

#include "VertexBufferObject.h"

class FloatVertexBufferObject : public VertexBufferObject
{
private:
	VertexData			_vertex_data;
	std::vector<float>	_packed_vertex_data;

public:
	FloatVertexBufferObject(VertexData& vertex_data, uint32_t location_offset);

	virtual void Create() override;
	virtual void Destroy() {}
	virtual void Bind() override;

	VertexData& GetVertexData();
	std::vector<float>& GetPackedVertexData();
};

#endif