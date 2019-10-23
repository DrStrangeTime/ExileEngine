#include "Editor.h"

//#include <algorithm>
//
//std::vector<Object*> Editor::objects;
//
//bool abstrSmaller(const Object* o1, const Object* o2) {
//	return o1->t < o2->t;
//}

void Editor::Initialise()
{
	// Initialise sub-modules
	exInit();	// Init ExCore.dll
	// Initialise glfw window and glew
	exCreateWindow(1920, 1080, "Exile Editor", true, false, true);
}

void Editor::Destroy()
{
	exDestroy();
}

void Editor::Event()
{
	// Input event handling here...
}

void Editor::Update()
{
	// Logic, Physics ect...
}

void Editor::Render()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT );



	exSwap();
}

void Editor::Run()
{
	Initialise();

	

	// --------------- LOOP ---------------
	while (exRunning())
	{
		exPollEvents();

		Update();
		Render();
	}
	// ------------------------------------

	Destroy();
}