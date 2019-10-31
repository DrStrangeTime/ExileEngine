#ifndef __WORLD_INFO_H__
#define __WORLD_INFO_H__

#include <vector>
#include "ActionMap.h"

class WorldInfo
{
private:
	// Input
	static std::vector<ActionMap>	_actionMaps;

	// Logic
	static double					_framesPerSecond;
	static double					_realtimeSpeed;

	// Rendering
	static double					_brightness;
	static double					_contrast;
	static double					_saturation;
	static bool						_fowardRendering;
	static bool						_twoDimensional;

public:
	static inline std::vector<ActionMap>&	GetActionMaps() { return _actionMaps; }
	static inline double&					GetFramesPerSecond() { return _framesPerSecond; }
	static inline double&					GetRealtimeSpeed() { return _realtimeSpeed; }
	static inline double&					GetBrightness() { return _brightness; }
	static inline double&					GetContrast() { return _contrast; }
	static inline double&					GetSaturation() { return _saturation; }
	static inline bool&						GetForwardRendering() { return _fowardRendering; }
	static inline bool&						GetTwoDimensional() { return _twoDimensional; }

	static inline void						AddActionMap(ActionMap value) { _actionMaps.push_back(value); }
	static inline void						SetFramesPerSecond(double value) { _framesPerSecond = value; }
	static inline void						SetRealtimeSpeed(double value) { _realtimeSpeed = value; }
	static inline void						SetBrightness(double value) { _brightness = value; }
	static inline void						SetContrast(double value) { _brightness = value; }
	static inline void						SetSaturation(double value) { _saturation = value; }
	static inline void						SetForwardRendering(bool value) { _fowardRendering = value; }
	static inline void						SetTwoDimensional(bool value) { _twoDimensional = value; }
};

#endif