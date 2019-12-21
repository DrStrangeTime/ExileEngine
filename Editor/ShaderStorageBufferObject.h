#ifndef __SHADER_STORAGE_BUFFER_OBJECT_H__
#define __SHADER_STORAGE_BUFFER_OBJECT_H__

#include "Buffer.h"
#include "BlockElement.h"

struct Data_c
{
	float scale;
};

class ShaderStorageBufferObject : public Buffer
{
private:
	uint32_t					_block_index;

public:
	ShaderStorageBufferObject(uint32_t block_index, GLsizeiptr initial_size);
	~ShaderStorageBufferObject();

	uint32_t&					GetBlockIndex();

	void						WriteData(const void* src);
	void						WriteDataRange(GLintptr offset, GLsizeiptr length, const void* src);
	void						ReadData(void* src);

	virtual void				Create() override;
	virtual void				Destroy() override;
	virtual void				Bind() override;
};

#endif