#ifndef __EX_AUDIO_H__
#define __EX_AUDIO_H__

#ifndef EXILE_AUDIO_EXPORTS
#define EXILE_AUDIO_API __declspec(dllexport)
#else
#define EXILE_AUDIO_API __declspec(dllimport)
#endif

#include "stdafx.h"

class EXILE_AUDIO_API t3
{
public:
	int x;
	inline t3() : x(0) {}
};

#define TEST3	t3;

#endif