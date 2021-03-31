#include "Game.h"

#include <stdlib.h>

int main(int argc, char* args[])
{
	//floatVec vec1(3.f, 1.f);
	//floatVec vec2 = 1.f * vec1;
	//vec2 = vec2 /norm(vec2);
	//std::cout << norm(vec2) << std::endl;
	//return 0;
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

