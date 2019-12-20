#ifndef __SHADER_STORAGE_BUFFER_OBJECT_H__
#define __SHADER_STORAGE_BUFFER_OBJECT_H__

#include "Buffer.h"
class ShaderStorageBufferObject : public Buffer
{
public:
	virtual void		Create() override;
	virtual void		Destroy() override;
	virtual void		Bind() override;
};

#endif