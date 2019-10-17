#ifndef __EX_RENDERER_H__
#define __EX_RENDERER_H__

#ifndef EXILE_RENDERER_EXPORTS
#define EXILE_RENDERER_API __declspec(dllexport)
#else
#define EXILE_RENDERER_API __declspec(dllimport)
#endif

#include "stdafx.h"

class EXILE_RENDERER_API t
{
public:
	int x;
	inline t() : x(0) {}
};

#define TEST	t;

#endif