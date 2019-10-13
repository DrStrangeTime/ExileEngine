#include "Editor.h"

//#include <algorithm>
//
//std::vector<Object*> Editor::objects;
//
//bool abstrSmaller(const Object* o1, const Object* o2) {
//	return o1->t < o2->t;
//}

std::thread	Editor::_update_thread;
std::mutex	Editor::_mutex;

void Editor::Create()
{
	// Initialise sub-modules
	exInit();	// Init ExCore.dll

	// Initialise window
	exCreateWindow(1920, 1080, "Exile Editor", true, false, true);

	StartThread();

	// Initialise ImGUI
	while (exRunning())
	{
		Render();
		exPollEvents();
	}
}

void Editor::Destroy()
{
	_update_thread.join();

	exDestroy();
}

void Editor::StartThread()
{	
	_update_thread = std::thread(Editor::Update);
}

void Editor::Update()
{
	// Physics & logic modulez
	while (exRunning())
	{
		std::cout << "UPDATING!\n";
	}
}

void Editor::Render()
{
	// Render module
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::cout << "RENDERING!\n";

	exSwap();

}
