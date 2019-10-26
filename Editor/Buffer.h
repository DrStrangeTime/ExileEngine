#ifndef __BUFFER_H__
#define __BUFFER_H__

#define SIZE_OF_FLOAT	static_cast<size_t>(sizeof(float))
#define SIZE_OF_UINT32	static_cast<size_t>(sizeof(uint32_t))

#include "Headers.h"

/* Abstract class for all buffers */
class Buffer
{
protected:
	uint32_t	_buffer_type;
	uint32_t	_buffer_object;
	size_t		_buffer_size;

public:
	uint32_t& GetBufferType();
	uint32_t& GetBufferObject();
	size_t& GetBufferSize();
	
	virtual void Create() = 0;
	virtual void Destroy() = 0;
	virtual void Bind() = 0;
};

#endif