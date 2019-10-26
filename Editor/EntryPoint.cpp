#include "Editor.h"


int main(int argc, char** argv)
{
	std::unique_ptr<Editor>app = std::make_unique<Editor>();

	app->Run();

	exit(EXIT_SUCCESS);
}