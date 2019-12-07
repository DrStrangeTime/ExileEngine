#include "GLSLLoader.h"


uint32_t GLSLLoader::CreateShader(std::map<uint32_t, const GLchar*>& shader_stages)
{
	uint32_t _program = glCreateProgram();	// The returning program

	// 1. Retrieve the vertex/fragment source code from filePath
	std::ifstream				shader_file;
	std::vector<GLuint>			shader_buffers;
	std::vector<uint32_t>		stage_types;
	std::vector<const GLchar*>	shader_uris;

	for (std::map<uint32_t, const GLchar*>::iterator it = shader_stages.begin(); it != shader_stages.end(); ++it)
	{
		stage_types.emplace_back(it->first);
		shader_uris.emplace_back(it->second);
	}

	for (unsigned i = 0; i < stage_types.size(); ++i)
	{
		std::string glsl_code;

		// ensures ifstream objects can throw exceptions:
		shader_file.exceptions(std::ifstream::badbit);
		try
		{
			// Open files

			shader_file.open(shader_uris[i]);
			std::stringstream shader_stream;

			// Read file's buffer contents into streams
			shader_stream << shader_file.rdbuf();

			// close file handlers
			shader_file.close();

			// Convert stream into string
			glsl_code = shader_stream.str();
		}
		catch (std::ifstream::failure e)
		{
#ifdef _DEBUG
			ExCore::Logger::PrintErr("Failed to read shader file!");
#endif
		}

		const GLchar* code_c = glsl_code.c_str();

		// Vertex Shader
		shader_buffers.emplace_back(glCreateShader(stage_types[i]));
		glShaderSource(shader_buffers[i], 1, &code_c, NULL);
		glCompileShader(shader_buffers[i]);

#ifdef _DEBUG
		GLint success(0);
		GLchar infoLog[512];
		glGetShaderiv(shader_buffers[i], GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader_buffers[i], 512, NULL, infoLog);
			ExCore::Logger::PrintErr(infoLog);
		}
#endif

		glAttachShader(_program, shader_buffers[i]);
	}

	glLinkProgram(_program);

#ifdef _DEBUG
	// Print linking errors if any
	GLint success(0);
	GLchar infoLog[512];
	glGetProgramiv(_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(_program, 512, NULL, infoLog);
		ExCore::Logger::PrintErr(infoLog);
	}
#endif

	// Delete the shaders as they're linked into our program now and no longer necessery

	for (unsigned i = 0; i < stage_types.size(); ++i)
		glDeleteShader(shader_buffers[i]);

	return _program;
}