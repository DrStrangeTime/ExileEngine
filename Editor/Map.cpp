#include "Map.h"

// Boolean comparison for std::sort
bool ActorTypeSmaller(std::shared_ptr<Actor> a1, std::shared_ptr<Actor> a2)
{
	return a1->GetType() < a2->GetType();
}

Map::Map(std::string name)
{
	SetName(name);
}

std::vector<std::shared_ptr<Actor>>& Map::GetActors()
{
	return _actors;
}

std::shared_ptr<Camera> Map::GetCameraObject()
{
	return std::dynamic_pointer_cast<Camera>(_actors[0]);
}

std::shared_ptr<CameraPerspective3D> Map::GetCameraPerspective3DObject()
{
	return std::dynamic_pointer_cast<CameraPerspective3D>(_actors[0]);
}

uint32_t Map::GetActorIndexByName(std::string value)
{
	for (unsigned int i = 0; i < _actors.size(); ++i)
	{
		std::string n = *_actors[i];
		if (n == value)
			return static_cast<uint32_t>(i);
	}

	ExLogErr("Failed to find actor index by name!");

	return 0;
}

std::shared_ptr<Actor> Map::GetActorByName(std::string value)
{
	for (unsigned int i = 0; i < _actors.size(); ++i)
	{
		std::string n = *_actors[i];
		if (n == value)
			return _actors[i];
	}

	ExLogErr("Failed to find actor by name!");

	return nullptr;
}

void Map::RemoveActorByIndex(uint32_t value)
{
	_actors.erase(_actors.begin() + value);
}

void Map::RemoveActorByName(std::string value)
{
	_actors.erase(_actors.begin() + GetActorIndexByName(value));
}

void Map::SortActorsByType()
{
	std::sort(_actors.begin(), _actors.end(), ActorTypeSmaller);
}

void Map::BindPlayerController()
{
	_actors[0]->Render();
}

void Map::BindStaticMeshData()
{
	for (auto i = _staticMeshOffsetData.begin; i < _staticMeshOffsetData.end; ++i)
		_actors[i]->Render();
}

void Map::BindSkeletalMeshData()
{
	for (auto i = _skeletalMeshOffsetData.begin; i < _skeletalMeshOffsetData.end; ++i)
		_actors[i]->Render();
}

void Map::BindParticleData()
{
	for (auto i = _particleOffsetData.begin; i < _particleOffsetData.end; ++i)
		_actors[i]->Render();
}

void Map::BindLightData()
{
	for (auto i = _lightOffsetData.begin; i < _lightOffsetData.end; ++i)
		_actors[i]->Render();
}

void Map::BindAllData()
{
	for (auto i = 0; i < _actors.size(); ++i)
		_actors[i]->Render();
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
			_actors.insert(_actors.begin() + i, value);
			break;
		}
	}

	// If non exists, push back as normal
	if (!typeExists)
		_actors.emplace_back(value);

	// Sort actor list for divising data
	if (_actors.size() > 1)
		SortActorsByType();
	
	// Manipulate data by analysing each type offset
	if (!_actors.empty())
	{
		// Pack temp analytical data to seperate containers
		bool firstType(true);
		std::vector<uint32_t> begin_list{ 0 };
		std::vector<uint32_t> end_list{ 1 };
		std::vector<uint32_t> type_list{ _actors[0]->GetType() };
		uint32_t offset_index = 0;
		uint32_t current_type = _actors[0]->GetType();
		for (unsigned int i = 1; i < _actors.size(); ++i)
		{
			if (current_type == _actors[i]->GetType())
			{
				end_list[offset_index]++;
				break;
			}
			else
			{
				current_type = _actors[i]->GetType();

				type_list.emplace_back(current_type);
				begin_list.emplace_back(end_list[offset_index]);
				end_list.emplace_back(end_list[offset_index] + 1);

				offset_index++;
			}
		}

		// Assign temp data into a set of fixed structs
		for (unsigned int i = 0; i < type_list.size(); ++i)
		{
			switch (type_list[i])
			{
			case A_STATIC_MESH:
				_staticMeshOffsetData = OffsetData(begin_list[i], end_list[i]);
				break;
			case A_SKELETAL_MESH:
				_skeletalMeshOffsetData = OffsetData(begin_list[i], end_list[i]);
				break;
			case A_LIGHT:
				_lightOffsetData = OffsetData(begin_list[i], end_list[i]);
				break;
			case A_PARTICLE_SYSTEM:
				_particleOffsetData = OffsetData(begin_list[i], end_list[i]);
				break;
			}
		}
	}
}