#include "FrameBufferTarget.h"

FrameBufferTarget::~FrameBufferTarget()
{
	Destroy();
}

inline void FrameBufferTarget::Destroy()
{
	glDeleteTextures(1, &_buffer_object);
}

inline void FrameBufferTarget::Bind()
{
	glBindTexture(GL_TEXTURE_2D, _buffer_object);
}