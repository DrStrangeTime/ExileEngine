#ifndef __ACTION_MAP_MOUSE_EVENT_H__
#define __ACTION_MAP_MOUSE_EVENT_H__

#include "ActionMap.h"

class ActionMapMouseEvent : public ActionMap
{
private:
	uint16_t	_button;

public:
	ActionMapMouseEvent(const char* name, uint16_t button, uint16_t state, uint16_t action);

	uint16_t& GetButton();

	virtual bool isActive() override;
};

#endif