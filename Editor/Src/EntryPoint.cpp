#include "headers.h"


int main(int argc, char** argv)
{

	/*EX_INIT;

	InitImGUI();

	while (EX_CORE_RUNNING)
	{
		EX_RENDER;
		iImGUIRender();
		
		EX_UPDATE;
	}

	EX_DESTROY;*/

	ExCore::Logger::Initialise("EXILE_ENGINE");

	ExCore::Logger::PrintWar("GFX hardware is limited to OpenGL version 330!");
	ExCore::Logger::PrintErr("Failed to initialise GLEW!");

	system("PAUSE");

	return 0;
}