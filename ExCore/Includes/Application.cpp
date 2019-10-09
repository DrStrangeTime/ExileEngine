#include "pch.h"
#include "Application.h"
#include "Logger.h"

void ExCore::Application::Create(int width, int height, const char* title)
{
	if (!glfwInit())
	{
		ExCore::Logger::PrintErr("Failed to initialise GLFW!");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "Simple example", NULL, NULL);

	if (!window)
	{
		ExCore::Logger::PrintErr("Failed to initialise GLFW window!");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	//glfwSetKeyCallback(window.get(), key_callback);


	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		ExCore::Logger::PrintErr("Failed to initialise GLAD!");
		Sleep(2000);
		glfwDestroyWindow(window);
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSwapInterval(1);

	// OpenGL properties
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, width, height);
}

void ExCore::Application::Destroy()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void ExCore::Application::Swap()
{
	glfwPollEvents();
	glfwSwapBuffers(window);
}

bool ExCore::Application::isRunning()
{
	return (!glfwWindowShouldClose(window));
}

int								ExCore::Application::width;
int								ExCore::Application::height;
const char*						ExCore::Application::title;
GLFWwindow*						ExCore::Application::window;