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

<<<<<<< HEAD
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
=======
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
>>>>>>> 19769aef8516a747dfdfd2f1ef02a3194883436e

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
<<<<<<< HEAD
		ExCore::Logger::PrintErr("Failed to initialise GLAD!");
=======
		ExCore::Logger::PrintErr("Failed to initialise GLEW!");
		Sleep(2000);
>>>>>>> 19769aef8516a747dfdfd2f1ef02a3194883436e
		glfwDestroyWindow(window);
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	glfwSwapInterval(1);

	std::vector<const char*> glSupport;

	// Get OpenGL versions on system
	if (GLEW_VERSION_1_1)
		glSupport.push_back("GL_VERSION_1_1");
	if (GLEW_VERSION_1_2)
		glSupport.push_back("GL_VERSION_1_2");
	if (GLEW_VERSION_1_2_1)
		glSupport.push_back("GL_VERSION_1_2_1");
	if (GLEW_VERSION_1_3)
		glSupport.push_back("GL_VERSION_1_3");
	if (GLEW_VERSION_1_4)
		glSupport.push_back("GL_VERSION_1_4");
	if (GLEW_VERSION_1_5)
		glSupport.push_back("GL_VERSION_1_5");
	if (GLEW_VERSION_2_0)
		glSupport.push_back("GL_VERSION_2_0");
	if (GLEW_VERSION_2_1)
		glSupport.push_back("GL_VERSION_2_1");
	if (GLEW_VERSION_3_0)
		glSupport.push_back("GL_VERSION_3_0");
	if (GLEW_VERSION_3_1)
		glSupport.push_back("GL_VERSION_3_1");
	if (GLEW_VERSION_3_2)
		glSupport.push_back("GL_VERSION_3_2");
	if (GLEW_VERSION_3_3)
		glSupport.push_back("GL_VERSION_3_3");
	if (GLEW_VERSION_4_0)
		glSupport.push_back("GL_VERSION_4_0");
	if (GLEW_VERSION_4_1)
		glSupport.push_back("GL_VERSION_4_1");
	if (GLEW_VERSION_4_2)
		glSupport.push_back("GL_VERSION_4_2");
	if (GLEW_VERSION_4_3)
		glSupport.push_back("GL_VERSION_4_3");
	if (GLEW_VERSION_4_4)
		glSupport.push_back("GL_VERSION_4_4");
	if (GLEW_VERSION_4_5)
		glSupport.push_back("GL_VERSION_4_5");
	if (GLEW_VERSION_4_6)
		glSupport.push_back("GL_VERSION_4_6");

	// Check for support of OpenGL
	if (glSupport.empty())
	{
		ExCore::Logger::PrintErr("This machine does not support OpenGL!");
		glfwDestroyWindow(window);
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	ExCore::Logger::PrintArray(&glSupport[0], glSupport.size(), "Supported OpenGL Versions");
	ExCore::Logger::PrintInfo(glGetString(GL_VERSION));		// Print latest opengl version on machine

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

int				ExCore::Application::width;
int				ExCore::Application::height;
const char*		ExCore::Application::title;
GLFWwindow*		ExCore::Application::window;