#include "DiffuseSF.h"

DiffuseSF::DiffuseSF()
{
	_shader_index = SHADER_DIFFUSE_FORWARD;

	Initialise();
}

void DiffuseSF::Initialise()
{
	std::map<uint32_t, const GLchar*> shader_stages{ { GL_VERTEX_SHADER, "shaders/forward/diffuse.vs" }, { GL_FRAGMENT_SHADER, "shaders/forward/diffuse.fs" } };
	_shader_buffer = std::make_shared<ShaderBuffer>(GLSLLoader::CreateShader(shader_stages));
}

void DiffuseSF::Bind()
{
	// Bind global uniforms here

	Shader::Bind();
}
