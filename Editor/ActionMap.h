#ifndef __ACTION_MAP_H__
#define __ACTION_MAP_H__

#include "Actions.h"

class ActionMap
{
private:
	const char*		_name;
	unsigned int	_key;
	unsigned int	_action;

public:
	ActionMap() = default;
	ActionMap(const char* name, unsigned int key, unsigned int action);

	const char* GetName();
	unsigned int GetKey();
	unsigned int GetAction();

	void SetName(const char* name);
	void SetKey(unsigned int key);
	void SetAction(unsigned int action);
	void Map(unsigned int key, unsigned int action);
};

#endif