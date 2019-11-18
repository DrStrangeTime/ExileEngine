#include "WorldInfo.h"

double										WorldInfo::_framesPerSecond = 6.f;
double										WorldInfo::_realtimeSpeed = 1.f;
std::vector<std::shared_ptr<ActionMap>>		WorldInfo::_actionMaps;