#include "DiffuseSF.h"

DiffuseSF::DiffuseSF()
{
	_shader_index = SHADER_DIFFUSE_FORWARD;

	Initialise();
}

void DiffuseSF::Initialise()
{
	_shader_buffer = std::make_shared<ShaderBuffer>(SHADER_TYPE_VERTEX, GLSLLoader::LoadVertFrag("shaders/forward/diffuse.vs", "shaders/forward/diffuse.fs"));
}

void DiffuseSF::Bind()
{
	// Bind global uniforms here

	Shader::Bind();
}
