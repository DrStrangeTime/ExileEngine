#pragma once

#include "TriangleTest.h"
#include "WorldInfo.h"


/* Editor derives from the Exile::Core application interface. */
class Editor : public ExCore::Application
{
private:
	// ------------- TEMP -------------
	static std::unique_ptr<TriangleTest>	tt;
	// --------------------------------

	static int								width;
	static int								height;
	static const char*						title;
	static GLFWwindow*						window;
	static ExCore::RenderDevice::Properties	rdp;

public:
	Editor();
	~Editor();

	static void Create(int w, int h, const char* title, bool maximise, bool fullscreen, bool showCursor);
	static void Destroy();
	static void FramebufferSize(GLFWwindow* window, int w, int h);
	static void KeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void MouseButtonEvent(GLFWwindow* window, int button, int action, int mods);
	static void MouseScrollEvent(GLFWwindow* window, double xoffset, double yoffset);
	static void MousePositionEvent(GLFWwindow* window, double xpos, double ypos);
	static void Swap();
	
	void Update(double delta) override;
	void Render() override;
	void Run() override;
	bool isRunning() override;


};