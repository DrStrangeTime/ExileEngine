#include "Editor.h"

void Editor::Create()
{
	// Initialise sub-modules
	exCoreInit();	// Init ExCore.dll

	// Initialise window
	exCoreCreateWindow(600, 500, "Exile Editor");

	// Initialise ImGUI

}

void Editor::Destroy()
{
	exCoreDestroy();
}

void Editor::Update()
{
	// Physics module
}

void Editor::Render()
{
	// Render module
}

// Main loop
void Editor::Loop()
{
	while (exCoreRunning())
	{;
		
		// Timestep here
		Update();
		// -------------

		Render();
#
		exCoreSwap();
	}
}

