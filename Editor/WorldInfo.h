#ifndef __WORLD_INFO_H__
#define __WORLD_INFO_H__

/* Contains global data about the world properties */
class WorldInfo
{
private:
	// Logic
	static double											_framesPerSecond;
	static double											_realtimeSpeed;

public:
	static inline double&									GetFramesPerSecond() { return _framesPerSecond; }
	static inline double&									GetRealtimeSpeed() { return _realtimeSpeed; }

	static inline void										SetFramesPerSecond(double value) { _framesPerSecond = value; }
	static inline void										SetRealtimeSpeed(double value) { _realtimeSpeed = value; }
};

#endif