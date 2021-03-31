#include "Game.h"

#include <stdlib.h>

int main(int argc, char* args[])
{
	Game* game = new Game;
	if (!game->init())
		return 0;
	game->loadLevel();
	game->gameLoop();
	game->cleanUp();
	delete game;
	game = NULL;
	return 0;
}

