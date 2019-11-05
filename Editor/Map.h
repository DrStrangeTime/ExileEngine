#ifndef __MAP_H__
#define __MAP_H__

#define NUM_ACTOR_TYPES		28

#include "Actor.h"

// A structure for storing filtered index data
struct ActorTypeOffsetData
{
	uint32_t type;
	uint32_t begin;
	uint32_t end;

	ActorTypeOffsetData() : type(0), begin(0), end(0) {}
	ActorTypeOffsetData(uint32_t t, uint32_t b, uint32_t e) {
		type = t;
		begin = b;
		end = e;
	}
};


/* The main map class that sorts and filters all actor objects inside one container.
   This class is a friend of Actor for accessing protected members such as _type. */

class Map : public Actor
{
private:
	std::vector<ActorTypeOffsetData>		_actorOffsetData;
	std::vector<std::shared_ptr<Actor>>		_actors;

public:
	void AddActor(std::shared_ptr<Actor> value);
	void RemoveActorByIndex(uint32_t value);
	void RemoveActorByName(std::string value);
	void SortActorsByType();

	uint32_t GetActorIndexByName(std::string value);
	std::shared_ptr<Actor> GetActorByName(std::string value);

	std::vector<std::shared_ptr<Actor>>& GetActors();
	std::vector<ActorTypeOffsetData>& GetActorOffsetData();
};

#endif