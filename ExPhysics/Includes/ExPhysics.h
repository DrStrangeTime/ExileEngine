#ifndef __EX_PHYSICS_H__
#define __EX_PHYSICS_H__

#ifndef EXILE_PHYSICS_EXPORTS
#define EXILE_PHYSICS_API __declspec(dllexport)
#else
#define EXILE_PHYSICS_API __declspec(dllimport)
#endif

#include "stdafx.h"

class EXILE_PHYSICS_API t2
{
public:
	int x;
	inline t2() : x(0) {}
};

#define TEST2	t2;

#endif