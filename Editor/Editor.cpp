#include "Editor.h"

#include <Query.h>

//#include <algorithm>
//
//std::vector<Object*> Editor::objects;
//
//bool abstrSmaller(const Object* o1, const Object* o2) {
//	return o1->t < o2->t;
//}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Editor::Editor()
{
	Create(600, 500, "Exile Editor", false, false, true);

	tt = std::make_unique<TriangleTest>();
}

Editor::~Editor()
{
	Destroy();
}

bool Editor::isRunning()
{
	return !glfwWindowShouldClose(window);
}

void Editor::Create(int w, int h, const char* title, bool maximise, bool fullscreen, bool showCursor)
{
	exInit();	// Init ExCore.dll

	width = w;
	height = h;

	glewExperimental = GL_TRUE;
	
	// Initialise GLFW
	if (!glfwInit())
	{
		ExCore::Logger::PrintErr("Failed to initialise GLFW!");
		exit(EXIT_FAILURE);
	}

	// Set GLFW window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	if (maximise)
		glfwWindowHint(GLFW_MAXIMIZED, 1);

	// Initialise windows
	window = glfwCreateWindow(width, height, "Exile Editor", NULL, NULL);
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
	ExCore::Cursor::Initialise(GLFW_ARROW_CURSOR);

	// GLFW Callback functions ----------------------------------------------------
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, InputManager::key_callback);
	glfwSetMouseButtonCallback(window, InputManager::mouse_button_callback);
	glfwSetCursorPosCallback(window, InputManager::cursor_position_callback);
	glfwSetScrollCallback(window, InputManager::scroll_callback);
	(!showCursor ? glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED) : glfwSetCursor(window, ExCore::Cursor::GetCursor()));
	// ----------------------------------------------------------------------------

	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &width, &height);

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
	//glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, width, height);
}

void Editor::Destroy()
{
	glfwDestroyCursor(ExCore::Cursor::GetCursor());
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Editor::PollEvents()
{
	glfwPollEvents();
}

void Editor::Update()
{
	// Interpolation, Physics ect...
}

void Editor::Render()
{
	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	tt->Render();

	Swap();
}

void Editor::Swap()
{
	glfwSwapBuffers(window);
}

void Editor::Run()
{
	ExCore::Timestep _f_time_step(FPS, REALTIME_SPEED);

	_f_time_step.Start();

	while (isRunning())
	{
		_f_time_step.CalcLastElapsed();
		while (_f_time_step.timeElapsed())
		{
			Update();
			_f_time_step.ResetElapsed();
		}
		_f_time_step.Lock();

		Render();

		PollEvents();
	}

	Destroy();
}