#include "Buffer.h"

uint32_t& Buffer::GetBufferType()
{
	return _buffer_type;
}

uint32_t& Buffer::GetBufferObject()
{
	return _buffer_object;
}

size_t& Buffer::GetBufferSize()
{
	return _buffer_size;
}
