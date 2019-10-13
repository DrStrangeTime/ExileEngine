#include "pch.h"
#include "Application.h"

void ExCore::Application::error_callback(int error, const char* description)
{
	ExCore::Logger::PrintErr(description);
}

void ExCore::Application::window_resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


void ExCore::Application::Create(int w, int h, const char* title, bool maximise, bool fullscreen, bool showCursor)
{
	width = w;
	height = h;

	// Initialise GLFW
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		ExCore::Logger::PrintErr("Failed to initialise GLFW!");
		exit(EXIT_FAILURE);
	}

	// Set GLFW window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	if (maximise)
		glfwWindowHint(GLFW_MAXIMIZED, 1);


	// Initialise windows
	window = glfwCreateWindow(width, height, "Exile Editor", (fullscreen ? glfwGetPrimaryMonitor() : NULL), NULL);
	if (!window)
	{
		ExCore::Logger::PrintErr("Failed to initialise GLFW window!");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Assign width and height of screen
	if (fullscreen)
	{
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		width = mode->width;
		height = mode->height;
	}

	// Initialise cursor
	ExCore::Cursor::Initialise();

	// GLFW Callback functions ----------------------------------------------------
	glfwSetErrorCallback(error_callback);
	glfwSetWindowSizeCallback(window, window_resize_callback);
	glfwSetKeyCallback(window, ExCore::InputEvent::key_callback);
	glfwSetMouseButtonCallback(window, ExCore::InputEvent::mouse_button_callback);
	glfwSetCursorPosCallback(window, ExCore::InputEvent::cursor_position_callback);
	glfwSetScrollCallback(window, ExCore::InputEvent::scroll_callback);
	(!showCursor ? glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED) : glfwSetCursor(window, ExCore::Cursor::GetCursor()));
	// ----------------------------------------------------------------------------

	glfwMakeContextCurrent(window);

	// Initialise GLEW
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
	glfwDestroyCursor(ExCore::Cursor::GetCursor());
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