#include "pch.h"
#include "Application.h"

void ExCore::Application::error_callback(int error, const char* description)
{
	ExCore::Logger::PrintErr(description);
}

void ExCore::Application::Create(int width, int height, const char* title, bool fullscreen)
{
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		ExCore::Logger::PrintErr("Failed to initialise GLFW!");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_MAXIMIZED, 1);

	window = glfwCreateWindow(width, height, "Exile Editor", (fullscreen ? glfwGetPrimaryMonitor() : NULL), NULL);

	if (!window)
	{
		ExCore::Logger::PrintErr("Failed to initialise GLFW window!");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	// GLFW Callback functions ----------------------------------------------------
	glfwSetKeyCallback(window, ExCore::InputEvent::key_callback);
	glfwSetMouseButtonCallback(window, ExCore::InputEvent::mouse_button_callback);
	glfwSetCursorPosCallback(window, ExCore::InputEvent::cursor_position_callback);
	glfwSetScrollCallback(window, ExCore::InputEvent::scroll_callback);
	GLFWcursor* cursor = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
	glfwSetCursor(window, cursor);
	// ----------------------------------------------------------------------------

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

	// Print hardware stats
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