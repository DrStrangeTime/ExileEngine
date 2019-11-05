#include "Map.h"

bool ActorTypeSmaller(std::shared_ptr<Actor> a1, std::shared_ptr<Actor> a2)
{
	return a1->GetType() < a2->GetType();
}



void Map::RemoveActorByIndex(uint32_t value)
{
	_actors.erase(_actors.begin() + value);
}

void Map::RemoveActorByName(std::string value)
{
	_actors.erase(_actors.begin() + GetActorIndexByName(value));
}

void Map::AddActor(std::shared_ptr<Actor> value)
{
	// Check for existing actor types in list
	bool typeExists(false);
	for (unsigned int i = 0; i < _actors.size(); ++i)
	{
		if (_actors[i]->GetType() == value->GetType())
		{
			typeExists = true;
			unsigned int index = i + 1;
			_actors.insert(_actors.begin() + index, value);
			break;
		}
	}

	// If non exists, push back as normal
	if (!typeExists)
		_actors.push_back(value);

	// Sort actor list for filtering
	if (_actors.size() > 1)
		SortActorsByType();

	// Assign filtered data by analysing each set of type offsets
	if (!_actors.empty())
	{
		
		for (unsigned int i = 0; i < _actors.size(); ++i)	// Iterate through each actor
		{


			for (unsigned int j = 0; j < NUM_ACTOR_TYPES; ++j)
			{

			}
		}
	}
}

void Map::SortActorsByType()
{
	std::sort(_actors.begin(), _actors.end(), ActorTypeSmaller);
}

uint32_t Map::GetActorIndexByName(std::string value)
{
	for (unsigned int i = 0; i < _components.size(); ++i)
	{
		std::string n = *_actors[i];
		if (n == value)
			return static_cast<uint32_t>(i);
	}

	exLogErr("Failed to find actor index by name!");

	return 0;
}

std::shared_ptr<Actor> Map::GetActorByName(std::string value)
{
	for (unsigned int i = 0; i < _components.size(); ++i)
	{
		std::string n = *_actors[i];
		if (n == value)
			return _actors[i];
	}

	exLogErr("Failed to find actor by name!");

	return nullptr;
}

std::vector<std::shared_ptr<Actor>>& Map::GetActors()
{
	return _actors;
}

std::vector<ActorTypeOffsetData>& Map::GetActorOffsetData()
{
	return _actorOffsetData;
}
