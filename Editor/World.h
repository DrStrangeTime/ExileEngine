#pragma once

#include "Map.h"

class World
{
private:
	static std::shared_ptr<Map> _map;

public:
	static void Initialise();
	static void EventKey(int key, int scancode, int mods);
	static void EventMouseButton(int button, int action, int mods);
	static void EventMouseScroll(double xoffset, double yoffset);
	static void Update(double delta);
	static void SubmitVertexData();
	static void SubmitLightData();
	static void SubmitParticleData();
	static void CompileData();
	
	static inline std::shared_ptr<Map>& GetMap() { return _map; }
};

