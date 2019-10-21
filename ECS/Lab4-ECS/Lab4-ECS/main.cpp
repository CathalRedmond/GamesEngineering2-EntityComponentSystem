#include "Game.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2main.lib")

int main(int argc, char* argv[])
{
	Game game;
	game.run();

	return EXIT_SUCCESS;
};