#ifndef __ACTION_MAP_KEYBOARD_EVENT_H__
#define __ACTION_MAP_KEYBOARD_EVENT_H__

#include "ActionMap.h"

class ActionMapKeyboardEvent : public ActionMap
{
private:
	uint32_t	_key;

public:
	ActionMapKeyboardEvent(const char* name, uint32_t key, uint16_t state, uint16_t action);

	uint32_t& GetKey();
	
	virtual bool isActive() override;
};

#endif