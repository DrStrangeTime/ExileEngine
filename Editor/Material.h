#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#define MAT_OPAQUE			0x0
#define MAT_TRANSPARENT		0x1
#define MAT_ADDITIVE		0x2
#define MAT_ANIMATION		0x3

#include "Texture.h"

/* The base material interface */
class Material
{
protected:
	float									_s;
	float									_t;
	uint16_t								_material_type;
	std::string								_name;
	std::vector<uint32_t>					_uniforms;
	std::vector<std::shared_ptr<Texture>>	_textures;

public:
	Material() : _s(1.f), _t(1.f),_material_type(0) {}

	float& GetS();
	float& GetT();

	inline void SetS(float value) { _s = value; }
	inline void SetT(float value) { _t = value; }
	
	virtual void Update() = 0;
	virtual void Bind() = 0;
};

#endif