#include "LogicManager.h"

void LogicManager::CloneDynamics()
{
	if (!_dynamic_actors.empty())
		_dynamic_actors.clear();

	for (std::shared_ptr<Actor> a : World::map->GetActors())
	{
		if (a->IsDynamic())
		{
			_dynamic_actors.reserve(1);
			_dynamic_actors.emplace_back(a);	// Clone instance of actor
		}
	}
}

void LogicManager::CompileDynamics()
{
	if (World::map->GetActors().empty())
	{
#ifdef _DEBUG
		ExCore::Logger::PrintErr("Failed to compile dynamic actors - list is empty!");
#endif
		return;
	}

	CloneDynamics();
}

void LogicManager::Update()
{
	for (auto i = 0; i < _dynamic_actors.size(); ++i)
		_dynamic_actors[i]->Update();
}


std::vector<std::shared_ptr<Actor>>		LogicManager::_dynamic_actors;