#ifndef __WORLD_INFO_H__
#define __WORLD_INFO_H__

#include <vector>
#include "ActionMapKeyboardEvent.h"
#include "ActionMapMouseEvent.h"

class WorldInfo
{
private:
	// Input
	static std::vector<std::shared_ptr<ActionMap>>			_actionMaps;

	// Logic
	static double											_framesPerSecond;
	static double											_realtimeSpeed;

	// Rendering
	static double											_brightness;
	static double											_contrast;
	static double											_saturation;
	static bool												_fowardRendering;
	static bool												_twoDimensional;

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
	static inline double&									GetBrightness() { return _brightness; }
	static inline double&									GetContrast() { return _contrast; }
	static inline double&									GetSaturation() { return _saturation; }
	static inline bool&										GetForwardRendering() { return _fowardRendering; }
	static inline bool&										GetTwoDimensional() { return _twoDimensional; }

	static inline void										AddActionMap(std::shared_ptr<ActionMap> value) { _actionMaps.push_back(value); }
	static inline void										SetFramesPerSecond(double value) { _framesPerSecond = value; }
	static inline void										SetRealtimeSpeed(double value) { _realtimeSpeed = value; }
	static inline void										SetBrightness(double value) { _brightness = value; }
	static inline void										SetContrast(double value) { _brightness = value; }
	static inline void										SetSaturation(double value) { _saturation = value; }
	static inline void										SetForwardRendering(bool value) { _fowardRendering = value; }
	static inline void										SetTwoDimensional(bool value) { _twoDimensional = value; }
};

#endif