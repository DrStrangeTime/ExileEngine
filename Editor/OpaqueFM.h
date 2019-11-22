#ifndef __OPAQUE_FM_H__
#define __OPAQUE_FM_H__

#include "Material.h"

class OpaqueFM : public Material
{
private:
	bool	_masked;

public:
	OpaqueFM(uint32_t& program, const char* name, bool masked, std::vector<Texture>& textures);

	virtual void Update() {}
	virtual void Bind() override;
};

#endif