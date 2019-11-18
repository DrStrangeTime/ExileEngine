#ifndef __LOGIC_MANAGER_H__
#define __LOGIC_MANAGER_H__

#include "World.h"

/* Contains a shared list of actors that use dynamics */
class LogicManager
{
private:
	static std::vector<std::shared_ptr<Actor>> _dynamic_actors;

	static void CloneDynamics();

public:
	static void CompileDynamics();
	static void Update();
};

#endif