#ifndef __UNIFORM_BLOCK_ELEMENT_H__
#define __UNIFORM_BLOCK_ELEMENT_H__

#include "Headers.h"

/* Contains information about a GLSL uniform block */
struct UniformBlockElement
{
	float*		data;
	uint32_t	offset;
	uint32_t	comp_size;
	uint32_t	size_in_bytes;

	UniformBlockElement() = default;
	UniformBlockElement(float* d, uint32_t cs) : data(nullptr), offset(0), comp_size(0), size_in_bytes(0)
	{
		if (!d)
		{
#ifdef _DEBUG
			ExLogErr("Data in uniform block element is empty!");
#endif
			return;
		}
		else if (cs <= 0)
		{
#ifdef _DEBUG
			ExLogErr("Component size in uniform block element is zero!");
#endif
			return;
		}

		Assign(d, cs);
	}

	void Assign(float* d = nullptr, uint32_t cs = 0)
	{
		data = d;
		comp_size = cs;
		size_in_bytes = comp_size * sizeof(float);
	}
};

#endif