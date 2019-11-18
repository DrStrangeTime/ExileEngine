#ifndef __MAP_H__
#define __MAP_H__

#include "OffsetData.h"
#include "ContentManager.h"

/* Camera presets */
#include "CameraPerspective3D.h"


/* The main map class that sorts and filters all actor objects inside one container */

class Map : public Object
{
private:
	OffsetData								_staticMeshOffsetData;
	OffsetData								_skeletalMeshOffsetData;
	OffsetData								_lightOffsetData;
	OffsetData								_particleOffsetData;

	std::vector <std::shared_ptr<Actor>>	_actors;

public:
	Map() = default;
	Map(std::string name);

	uint32_t								GetActorIndexByName(std::string value);
	std::shared_ptr<Actor>					GetActorByName(std::string value);
	std::vector<std::shared_ptr<Actor>>&	GetActors();

	std::shared_ptr<Camera>					GetCameraObject();
	
	void									AddActor(std::shared_ptr<Actor> value);
	void									RemoveActorByIndex(uint32_t value);
	void									RemoveActorByName(std::string value);
	void									SortActorsByType();

	void									BindPlayerController();
	void									BindStaticMeshData();
	void									BindSkeletalMeshData();
	void									BindParticleData();
	void									BindLightData();
	void									BindAllData();
};

#endif