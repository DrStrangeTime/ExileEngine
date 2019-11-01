#ifndef __ACTION_MAP_H__
#define __ACTION_MAP_H__

#include "InputEvent.h"
#include "ActionDefinitions.h"

class ActionMap
{
protected:
	bool			_state;
	const char*		_name;
	uint16_t		_action;

public:
	~ActionMap() = default;

	bool& GetState();
	const char* GetName();
	uint16_t& GetAction();

	virtual bool isActive() = 0;

};

#endif