#ifndef __FRAME_BUFFER_TARGET_H__
#define __FRAME_BUFFER_TARGET_H__

#include "Buffer.h"

/* Abstract frame buffer target class */
class FrameBufferTarget : public Buffer
{
protected:
	size_t	_width;
	size_t	_height;
	GLint	_internal_format;
	GLenum	_format;
	GLenum	_data_type;
	GLenum	_attachment_type;

	FrameBufferTarget() :	_width(0), 
							_height(0), 
							_internal_format(0),
							_format(0), 
							_data_type(0), 
							_attachment_type(0) {}

	virtual ~FrameBufferTarget();
	
public:
	virtual void	Create() = 0;
	virtual void	Destroy() override;
	virtual void	Bind() = 0;
};

#endif