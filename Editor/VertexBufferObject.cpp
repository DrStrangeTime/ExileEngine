#include "VertexBufferObject.h"

VertexBufferObject::~VertexBufferObject()
{
	Destroy();
}

void VertexBufferObject::Destroy()
{
	glDeleteBuffers(1, &_buffer_object);
}

void VertexBufferObject::Bind()
{
	glBindBuffer(_buffer_type, _buffer_object);
}