#pragma once

#include "InputManager.h"
#include "TriangleTest.h"

#define FPS				static_cast<double>(60.0)
#define REALTIME_SPEED	static_cast<double>(1.0)


/* Editor derives from the Exile::Core application interface. */
class Editor : public ExCore::Application
{
private:
	// ------------- TEMP -------------
	std::unique_ptr<TriangleTest>	tt;
	// --------------------------------

	void Update();
	void Render();

public:
	Editor();
	~Editor();

	void Create(int width, int height, const char* title, bool maximise, bool fullscreen, bool showCursor) override;
	void Destroy() override;
	void PollEvents() override;
	void Swap() override;
	void Run() override;
	bool isRunning() override;
};