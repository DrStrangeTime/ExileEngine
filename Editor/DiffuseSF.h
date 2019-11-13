#ifndef __DIFFUSE_SF_H__
#define __DIFFUSE_SF_H__

#include "Shader.h"

class DiffuseSF : public Shader
{
public:
	DiffuseSF();

	virtual void Initialise() override;
	virtual void Bind();
};

#endif