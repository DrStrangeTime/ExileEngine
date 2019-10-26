#include "ShaderLoader.h"

ShaderLoader::ShaderLoader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string		vertexCode;
	std::string		fragmentCode;
	std::ifstream	vShaderFile;
	std::ifstream	fShaderFile;

	// ensures ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::badbit);
	try
	{
		// Open files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;

		// Read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		// close file handlers
		vShaderFile.close();
		fShaderFile.close();

		// Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		ExCore::Logger::PrintErr("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
	}
	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();

	// 2. Compile shaders
	GLuint vertex, fragment;
	GLint success;
	GLchar infoLog[512];

	// Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	// Print compile errors if any
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		ExCore::Logger::PrintErr("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
	}

	// Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	// Print compile errors if any
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		ExCore::Logger::PrintErr("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
	}

	// Shader Program
	this->_program = glCreateProgram();
	glAttachShader(this->_program, vertex);
	glAttachShader(this->_program, fragment);
	glLinkProgram(this->_program);

	// Print linking errors if any
	glGetProgramiv(this->_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->_program, 512, NULL, infoLog);
		ExCore::Logger::PrintErr("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
	}

	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

ShaderLoader::~ShaderLoader()
{
	glDeleteProgram(_program);
}

void ShaderLoader::Bind()
{
	glUseProgram(_program);
}
