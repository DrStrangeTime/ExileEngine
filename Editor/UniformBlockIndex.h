#ifndef __UNIFORM_BLOCK_INDEX_H__
#define __UNIFORM_BLOCK_INDEX_H__

#include "Headers.h"

/* This object is used for getting uniform block index data and linking to a uniform binding point */
struct UniformBlockIndex
{
	uint32_t	block_index;
	uint32_t	point_index;

	explicit UniformBlockIndex() : point_index(0), block_index(0) {}
	UniformBlockIndex(uint32_t program, const char* block_name, uint32_t point_i)
	{
		point_index = point_i;
		AssignBlockIndex(program, block_name);
		BindBlockToPoint(program);
	}

	inline void AssignBlockIndex(uint32_t program, const char* block_name)
	{
		block_index = glGetUniformBlockIndex(program, block_name);
	}

	inline void BindBlockToPoint(uint32_t program)
	{
		glUniformBlockBinding(program, block_index, point_index);
	}
};

#endif