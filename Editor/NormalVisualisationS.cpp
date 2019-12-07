#include "NormalVisualisationS.h"

NormalVisualisation::NormalVisualisation()
{
	_shader_index = 1;

	Initialise();
}

void NormalVisualisation::Initialise()
{
	std::map<uint32_t, const GLchar*> shader_stages{ { GL_VERTEX_SHADER, "shaders/debug/normal_visualisation.vs" }, { GL_FRAGMENT_SHADER, "shaders/debug/normal_visualisation.fs" }, { GL_GEOMETRY_SHADER, "shaders/debug/normal_visualisation.geom" } };
	_shader_buffer = std::make_shared<ShaderBuffer>(GLSLLoader::CreateShader(shader_stages));
}

void NormalVisualisation::Bind()
{
	// Bind global uniforms here

	Shader::Bind();
}
