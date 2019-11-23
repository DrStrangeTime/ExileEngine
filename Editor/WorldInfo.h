#ifndef __WORLD_INFO_H__
#define __WORLD_INFO_H__

#include <vector>
#include "ActionMapKeyboardEvent.h"
#include "ActionMapMouseEvent.h"

/* Contains global data about the world properties */
class WorldInfo
{
private:
	// Input
	static std::vector<std::shared_ptr<ActionMap>>			_actionMaps;

	// Logic
	static double											_framesPerSecond;
	static double											_realtimeSpeed;

public:
	static inline std::shared_ptr<ActionMap>				GetActionMapByID(uint32_t value) { return (value > (_actionMaps.size() - 1) ? _actionMaps[value] : std::make_shared<ActionMapKeyboardEvent>("", 0, 0, 0)); }
	static inline std::shared_ptr<ActionMap>				GetActionMapByName(const char* value) { 
															for (auto i = 0; i < _actionMaps.size(); ++i)
																if (_actionMaps[i]->GetName() == value)
																	return _actionMaps[i];

																return std::make_shared<ActionMapKeyboardEvent>("", 0, 0, 0);
															}

	static inline double&									GetFramesPerSecond() { return _framesPerSecond; }
	static inline double&									GetRealtimeSpeed() { return _realtimeSpeed; }

	static inline void										AddActionMap(std::shared_ptr<ActionMap> value) { _actionMaps.emplace_back(value); }
	static inline void										SetFramesPerSecond(double value) { _framesPerSecond = value; }
	static inline void										SetRealtimeSpeed(double value) { _realtimeSpeed = value; }
};

#endif