#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include "pch.h"
#include "ExCore.h"

namespace ExCore
{
	namespace RenderDevice
	{
		struct Properties
		{
			const GLubyte*	vendor;
			const GLubyte*	model;
			const GLubyte*	gl_version;

			inline void Assign(const GLubyte* v, const GLubyte* m, const GLubyte* g)
			{
				vendor = v;
				model = m;
				gl_version = g;
			}
		};
	}
}

#endif