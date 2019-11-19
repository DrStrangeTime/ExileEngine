#ifndef __PRECISION_H__
#define __PRECISION_H__

#include "pch.h"
#include "ExCore.h"

#ifdef PI
#undef PI
#endif

/* Macro definitions */
#define PI	3.141592653589793238463

namespace ExCore
{
	class EXILE_CORE_API Precision
	{
	public:
		/* Precision operations */
		template <typename T> static T ToRadians(T x) { return (x * (static_cast<T>(PI) / static_cast<T>(180))); }
		template <typename T> static T ToDegrees(T x) { return (x * (static_cast<T>(180) / static_cast<T>(PI))); }
	};
}

#endif