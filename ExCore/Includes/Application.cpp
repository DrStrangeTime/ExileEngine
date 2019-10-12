#include "pch.h"
#include "Application.h"

void ExCore::Application::error_callback(int error, const char* description)
{
	ExCore::Logger::PrintErr(description);
}

void ExCore::Application::Create(int width, int height, const char* title)
{
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		ExCore::Logger::PrintErr("Failed to initialise GLFW!");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	window = glfwCreateWindow(width, height, "Exile Editor", NULL, NULL);

	if (!window)
	{
		ExCore::Logger::PrintErr("Failed to initialise GLFW window!");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, ExCore::InputEvent::key_callback);
	glfwSetMouseButtonCallback(window, ExCore::InputEvent::mouse_button_callback);

	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		ExCore::Logger::PrintErr("Failed to initialise GLEW!");
		glfwDestroyWindow(window);
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	glfwSwapInterval(1);

	rdp.Assign(glGetString(GL_VENDOR), glGetString(GL_RENDERER), glGetString(GL_VERSION));	// Store hardware properties

	ExCore::Logger::PrintInfo(rdp.vendor);
	ExCore::Logger::PrintInfo(rdp.model);
	ExCore::Logger::PrintInfo(rdp.gl_version);

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

void ExCore::Application::PollEvents()
{
	glfwPollEvents();
}

void ExCore::Application::Swap()
{
	glfwSwapBuffers(window);
}

bool ExCore::Application::isRunning()
{
	return (!glfwWindowShouldClose(window));
}

int										ExCore::Application::width;
int										ExCore::Application::height;
const char*								ExCore::Application::title;
GLFWwindow*								ExCore::Application::window;
ExCore::RenderDevice::Properties		ExCore::Application::rdp;