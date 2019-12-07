#include "FrameBufferTarget.h"

FrameBufferTarget::~FrameBufferTarget()
{
	Destroy();
}

inline void FrameBufferTarget::Destroy()
{
	glDeleteTextures(1, &_buffer_object);
}