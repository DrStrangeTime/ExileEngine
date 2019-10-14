#include "Editor.h"

//#include <algorithm>
//
//std::vector<Object*> Editor::objects;
//
//bool abstrSmaller(const Object* o1, const Object* o2) {
//	return o1->t < o2->t;
//}

std::thread	Editor::_update_thread;

void Editor::Initialise()
{
	// Initialise sub-modules
	exInit();	// Init ExCore.dll
	// Initialise window
	exCreateWindow(1920, 1080, "Exile Editor", true, false, true);
}

void Editor::Destroy()
{
	_update_thread.join();
	exDestroy();
}

void Editor::StartUpdateThread()
{	
	_update_thread = std::thread(Editor::Update);
}

void Editor::Update()
{
	while (exRunning())
	{
		// Timestep capping here

		//std::cout << "PHYSICS THREAD!\n";
	}
}

void Editor::Render()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//std::cout << "RENDERING!\n";

	exSwap();
}

void Editor::Loop()
{
	Initialise();

	// --------------- LOOP ---------------
	StartUpdateThread();
	while (exRunning())
	{
		Render();
		exPollEvents();
	}
	// ------------------------------------

	Destroy();
}