#include "Editor.h"
#include "stb_image.h"


void Editor::FramebufferSize(GLFWwindow* window, int w, int h)
{
	width = w;
	height = h;

	glViewport(0, 0, w, h);
}

bool Editor::isRunning()
{
	return !glfwWindowShouldClose(window);
}

Editor::Editor()
{
	Create(600, 500, "Exile Editor", false, false, true);
}

Editor::~Editor()
{
	Destroy();
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
#ifdef _DEBUG
		ExCore::Logger::PrintErr("Failed to initialise GLFW!");
#endif
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
#ifdef _DEBUG
		ExCore::Logger::PrintErr("Failed to initialise GLFW window!");
#endif
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
	glfwSetFramebufferSizeCallback(window, FramebufferSize);
	glfwSetKeyCallback(window, KeyEvent);
	glfwSetMouseButtonCallback(window, MouseButtonEvent);
	glfwSetCursorPosCallback(window, MousePositionEvent);
	glfwSetScrollCallback(window, MouseScrollEvent);
	(!showCursor ? glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED) : glfwSetCursor(window, ExCore::Cursor::GetCursor()));
	// ----------------------------------------------------------------------------

	// Load app icon
	GLFWimage icon;
	icon.pixels = stbi_load("icons/win_icon.png", &icon.width, &icon.height, 0, 4);
	glfwSetWindowIcon(window, 1, &icon);
	stbi_image_free(icon.pixels);

	// Set rendering context
	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &width, &height);

	// Initialise GLEW
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
#ifdef _DEBUG
		ExCore::Logger::PrintErr("Failed to initialise GLEW!");
#endif
		glfwDestroyWindow(window);
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Enable v-sync
	glfwSwapInterval(1);

	// Get hardware information
	rdp.Assign(glGetString(GL_VENDOR), glGetString(GL_RENDERER), glGetString(GL_VERSION));	// Store hardware properties

#ifdef _DEBUG
	ExCore::Logger::PrintInfo(rdp.vendor);
	ExCore::Logger::PrintInfo(rdp.model);
	ExCore::Logger::PrintInfo(rdp.gl_version);
#endif

	// OpenGL properties
	//glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);
	glClearColor(0.075f, 0.075f, 0.075f, 1.0f);
	glViewport(0, 0, width, height);


	// Initialise default action mapping data
	WorldInfo::AddActionMap(std::make_unique<ActionMapKeyboardEvent>("MoveFoward", GLFW_KEY_W, GLFW_PRESS, A_MOVE_FORWARD));
	WorldInfo::AddActionMap(std::make_unique<ActionMapKeyboardEvent>("MoveBackward", GLFW_KEY_S, GLFW_PRESS, A_MOVE_BACKWARD));
	WorldInfo::AddActionMap(std::make_unique<ActionMapKeyboardEvent>("MoveLeft", GLFW_KEY_A, GLFW_PRESS, A_MOVE_LEFT));
	WorldInfo::AddActionMap(std::make_unique<ActionMapKeyboardEvent>("MoveRight", GLFW_KEY_D, GLFW_PRESS, A_MOVE_RIGHT));

	// ------------- TEMP -------------
	//tt = std::make_unique<TriangleTest>();
	// --------------------------------

	RenderMaster::Initialise(USE_OPENGL | USE_FORWARD);
	//LogicMaster::Initialise();
	//AudioMaster::Initialise();

	GLWorld::Initialise();
}

void Editor::Destroy()
{
	glfwDestroyCursor(ExCore::Cursor::GetCursor());
	glfwDestroyWindow(window);
	glfwTerminate();
}

// ---------------------------------------------------------------------- CALLBACK FUNCTIONS ----------------------------------------------------------------------
void Editor::KeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	ExCore::KeyInput::UpdateKey(key, scancode, action, mods);
}

void Editor::MouseButtonEvent(GLFWwindow* window, int button, int action, int mods)
{
	ExCore::MouseInput::UpdateButton(button, action, mods);
}

void Editor::MouseScrollEvent(GLFWwindow* window, double xoffset, double yoffset)
{
	ExCore::MouseInput::UpdateScroll(xoffset, yoffset);
}

void Editor::MousePositionEvent(GLFWwindow* window, double xpos, double ypos)
{
	ExCore::MouseInput::UpdatePosition(xpos, ypos);
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------

void Editor::Update()
{
	// Interpolation, Physics ect...
	//LogicMaster::Update();
}

void Editor::Render(double &delta)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderMaster::Render(delta);

	Swap();
}

void Editor::Swap()
{
	glfwSwapBuffers(window);
}

void Editor::Run()
{
	ExCore::Timestep _f_time_step(WorldInfo::GetFramesPerSecond());
	double delta = 0;

	// Main loop
	while (isRunning())
	{
		_f_time_step.CalcLastElapsed();
		while (_f_time_step.timeElapsed())
		{
			Update();
			_f_time_step.ResetElapsed();
		}
		_f_time_step.Lock();

		Render(delta);

		glfwPollEvents();
	}
}


//std::unique_ptr<TriangleTest>		Editor::tt;

int									Editor::width;
int									Editor::height;
const char*							Editor::title;
GLFWwindow*							Editor::window;
ExCore::RenderDevice::Properties	Editor::rdp;