#pragma once

#include "InputManager.h"
#include "TriangleTest.h"

class Editor : public ExCore::Application
{
private:
	std::unique_ptr<TriangleTest> tt;

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