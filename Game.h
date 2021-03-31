#pragma once
#include "ResourceManager.h"

const float FPS = 60;
const int milliSecondsPerFrame = int(1000.f / FPS);

const std::string texturePath = "assets/sprites.png";

class Game
{
public:
	Game();
	~Game();
	bool init();
	bool loadLevel();
	void cleanUp();
	void gameLoop();
private:
	ResourceManager* manager;
	SDL_Window* window;
	SDL_Renderer* renderer;
};