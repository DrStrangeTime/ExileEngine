#include "Editor.h"

void Editor::Create()
{
	// Initialise sub-modules
	exInit();	// Init ExCore.dll

	// Initialise window
	exCreateWindow(1920, 1080, "Exile Editor", false);

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

