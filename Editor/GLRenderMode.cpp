#include "GLRenderMode.h"

std::vector<std::shared_ptr<Shader>>& GLRenderMode::GetShaders()
{
	return _shaders;
}

std::vector<std::shared_ptr<Shader>>& GLRenderMode::GetActiveShaders()
{
	return _active_shaders;
}