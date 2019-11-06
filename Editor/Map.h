#ifndef __MAP_H__
#define __MAP_H__

#include "Actor.h"
#include "OffsetData.h"


/* The main map class that sorts and filters all actor objects inside one container.
   This class is a friend of Actor for accessing protected members such as _type. */

class Map : public Actor
{
private:
	OffsetData								_staticMeshOffsetData;
	OffsetData								_skeletalMeshOffsetData;
	OffsetData								_particleOffsetData;
	OffsetData								_lightOffsetData;

	std::vector <std::shared_ptr<Actor>>	_actors;

public:
	uint32_t								GetActorIndexByName(std::string value);
	std::shared_ptr<Actor>					GetActorByName(std::string value);
	std::vector<std::shared_ptr<Actor>>&	GetActors();
	
	void AddActor(std::shared_ptr<Actor> value);
	void RemoveActorByIndex(uint32_t value);
	void RemoveActorByName(std::string value);
	void SortActorsByType();

	void SubmitStaticMeshData();
	void SubmitSkeletalMeshData();
	void SubmitParticleData();
	void SubmitLightData();

	virtual void EventKey(int key, int scancode, int mods)override;
	virtual void EventMouseButton(int button, int action, int mods)override;
	virtual void EventMouseScroll(double xoffset, double yoffset)override;
	virtual void Update() override;
	virtual void Render() override {}
};

#endif