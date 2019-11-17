#include "Client.h"


int main(int argc, char** argv)
{
	std::unique_ptr<Client>app = std::make_unique<Client>();

	app->Run();

	exit(EXIT_SUCCESS);
}