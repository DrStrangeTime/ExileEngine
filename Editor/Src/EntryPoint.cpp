#include "Editor.h"


int main(int argc, char** argv)
{
	Editor::Create();
	Editor::Loop();
	Editor::Destroy();

	exit(EXIT_SUCCESS);
}