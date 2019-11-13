#ifndef __ALBEDO_T_H__
#define __ALBEDO_T_H__

#include "Texture.h"

class AlbedoT : public Texture
{
public:
	AlbedoT(uint32_t program, const char* file, std::string name, uint32_t wrap, uint32_t filter, uint32_t mat_id);

	virtual void Bind();
};

#endif