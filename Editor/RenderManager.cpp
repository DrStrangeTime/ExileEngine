#include "RenderManager.h"

void RenderManager::RenderStaticMeshData()
{
	GLWorld::map->SubmitStaticMeshData();
}

void RenderManager::RenderSkeletalMeshData()
{
	GLWorld::map->SubmitSkeletalMeshData();
}

void RenderManager::RenderParticleData()
{
	GLWorld::map->SubmitParticleData();
}

void RenderManager::RenderLightData()
{
	GLWorld::map->SubmitLightData();
}

void RenderManager::RenderGUIData()
{
	//GLWorld::gui->SubmitGUIData();
}
