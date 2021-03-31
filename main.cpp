#include "Game.h"

#include <stdlib.h>

int main(int argc, char* args[])
{
	/*floatVec vec1(2.f, 2.f);
	floatVec vec2 = 3.f * vec1;
	vec2 = vec2 * 3.f;
	return 0;*/
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

