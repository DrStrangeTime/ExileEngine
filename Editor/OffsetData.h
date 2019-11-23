#ifndef __OFFSET_DATA_H__
#define __OFFSET_DATA_H__

#include "Headers.h"

/* A structure for storing index offset data */
struct OffsetData
{
	uint32_t	begin;
	uint32_t	end;

	OffsetData() : begin(0), end(0) {}
	OffsetData(uint32_t b, uint32_t e) {
		begin = b;
		end = e;
	}
};

#endif