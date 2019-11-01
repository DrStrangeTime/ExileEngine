#pragma once

#include "InputManager.h"
#include "TriangleTest.h"
#include "WorldInfo.h"


/* Editor derives from the Exile::Core application interface. */
class Editor : public ExCore::Application
{
private:
	// ------------- TEMP -------------
	std::unique_ptr<TriangleTest>	tt;
	// --------------------------------

	void Event();
	void Update(double delta);
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