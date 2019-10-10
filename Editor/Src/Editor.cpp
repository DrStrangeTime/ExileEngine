#include "Editor.h"

void Editor::Create()
{
	// Initialise sub-modules
	exInit();	// Init ExCore.dll

	// Initialise window
	exCreateWindow(600, 500, "Exile Editor");

	// Initialise ImGUI

}

void Editor::Destroy()
{
	exDestroy();
}

void Editor::Update()
{
	// Physics & logic module
}

void Editor::Render()
{
	// Render module
}

// Main loop
void Editor::Loop()
{
	while (exRunning())
	{;
		// Timestep here
		Update();
		// -------------

		Render();

		exPollEvents();
		exSwap();
	}
}

