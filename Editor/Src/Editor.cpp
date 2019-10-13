#include "Editor.h"


//#include <algorithm>
//
//std::vector<Object*> Editor::objects;
//
//bool abstrSmaller(const Object* o1, const Object* o2) {
//	return o1->t < o2->t;
//}


void Editor::Create()
{
	// Initialise sub-modules
	exInit();	// Init ExCore.dll

	// Initialise window
	exCreateWindow(1920, 1080, "Exile Editor", true, false, true);

	// Initialise ImGUI

	/*objects.push_back(new Material());
	objects.push_back(new StaticMesh());
	objects.push_back(new Material());
	objects.push_back(new Texture());
	objects.push_back(new StaticMesh());
	objects.push_back(new Texture());
	objects.push_back(new StaticMesh());

	std::sort(objects.begin(), objects.end(), abstrSmaller);

	std::vector<int> types;
	for (unsigned int i = 0; i < objects.size(); i++)
		types.push_back(objects[i]->t);

	objects.clear();

	ExCore::Logger::PrintArray(&types[0], types.size(), "Object Types");*/
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

