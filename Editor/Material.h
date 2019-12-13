#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#define MAT_OPAQUE			STATIC_CAST(uint16_t, 0x0)
#define MAT_TRANSPARENT		STATIC_CAST(uint16_t, 0x1)
#define MAT_ADDITIVE		STATIC_CAST(uint16_t, 0x2)

#include "Texture.h"

/* The base material interface */
class Material
{
protected:
	float									_s;
	float									_t;
	bool									_two_sided;
	uint16_t								_material_type;
	const char*								_name;
	std::vector<uint32_t>					_uniforms;
	std::vector<Texture>					_textures;

public:
	Material() :	_s(1.f),
					_t(1.f),
					_material_type(0),
					_name(""),
					_two_sided(false) {}

	Material(const char* name, uint16_t mat_type, bool two_sided, std::vector<Texture>& textures) :		_s(1.f),
																										_t(1.f),
																										_material_type(mat_type),
																										_name(name),
																										_two_sided(two_sided) {}

	float& GetS();
	float& GetT();

	inline void SetS(float value) { _s = value; }
	inline void SetT(float value) { _t = value; }
};

#endif