#include "Client.h"


int main(int argc, char** argv)
{
	ExCoreInit();	// Init ExCore.dll

	try {
		std::unique_ptr<Client>app = std::make_unique<Client>();
		app->Run();
	}
	catch (std::bad_alloc & ba) {
		std::cout << "BAD_ALLOCATION::APPLICATION_ERROR: " << ba.what() << "\n";
		return EXIT_FAILURE;
	}

	exit(EXIT_SUCCESS);
}