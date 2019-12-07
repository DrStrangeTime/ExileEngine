#ifndef __NORMAL_VISUALISATION_H__
#define __NORMAL_VISUALISATION_H__

#include "Shader.h"

class NormalVisualisation : public Shader
{
public:
	NormalVisualisation();

	virtual void Initialise() override;
	virtual void Bind();
};

#endif