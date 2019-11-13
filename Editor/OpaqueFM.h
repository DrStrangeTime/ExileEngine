#ifndef __OPAQUE_FM_H__
#define __OPAQUE_FM_H__

#include "Material.h"

class OpaqueFM : public Material
{
private:
	bool	_masked;

public:
	OpaqueFM(uint32_t program, std::string name, bool masked, std::vector<std::shared_ptr<Texture>> textures);

	virtual void Update() {}
	virtual void Bind() override;
};

#endif