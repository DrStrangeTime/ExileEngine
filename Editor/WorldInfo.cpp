#include "WorldInfo.h"

double					WorldInfo::_framesPerSecond = 6.0;
double					WorldInfo::_realtimeSpeed = 1.0;
double					WorldInfo::_brightness = 1.0;
double					WorldInfo::_contrast = 0.0;
double					WorldInfo::_saturation = 1.0;
bool					WorldInfo::_fowardRendering = false;
bool					WorldInfo::_twoDimensional = false;
std::vector<ActionMap>	WorldInfo::_actionMaps;

