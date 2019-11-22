#ifndef __INDEX_BUFFER_OBJECT_H__
#define __INDEX_BUFFER_OBJECT_H__

#include "Buffer.h"

class IndexBufferObject : public Buffer
{
private:
	GLsizei					_index_size;
	std::vector<uint32_t>	_index_data;

public:
	IndexBufferObject() : _index_size(0) {}
	IndexBufferObject(std::vector<uint32_t> index_data);
	~IndexBufferObject();

	void Create() override;
	void Destroy() override;
	void Bind() override;

	GLsizei& GetIndexSize();
	std::vector<uint32_t>& GetIndexData();
};

#endif