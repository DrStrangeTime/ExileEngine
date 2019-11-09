#ifndef __LOGIC_MANAGER_H__
#define __LOGIC_MANAGER_H__

#include "GLWorld.h"

/* This class manages all of the render functions from GLWorld. */
class RenderManager
{
public:
	static void RenderStaticMeshData();
	static void RenderSkeletalMeshData();
	static void RenderParticleData();
	static void RenderLightData();
	static void RenderGUIData();
};

#endif