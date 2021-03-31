#include "Game.h"

Game::Game()
{
	window = NULL;
	renderer = NULL;
	manager = NULL;
}

Game::~Game()
{
	
}
bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			//renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	manager = new ResourceManager;
	manager->load(texturePath, renderer);
	return success;
}

void Game::cleanUp()
{
	//Free loaded images
//gSpriteSheetTexture.free();

//Destroy window	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	delete manager;
	manager = NULL;

	return;
}

bool Game::loadLevel()
{
	bool success = true;
	Player* obj = new Player;
	manager->add(obj);
	return success;
}

void Game::gameLoop()
{
	bool quit = false;
	SDL_Event e;
	int prevTime = SDL_GetTicks();
		while (!quit)
		{
			//handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//user requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
	
			//clear screen
			SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xff);
			SDL_RenderClear(renderer);
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		
			manager->processInput(currentKeyStates);
	
			int currTime = SDL_GetTicks();
			if (currTime - prevTime < 0) //if time overflows, continue
				continue;
			int t = currTime - prevTime;
		
			manager->update(float(t));
		
			prevTime = currTime;
			int sleepTime = milliSecondsPerFrame-t; //cap framerate
			if (sleepTime > 0)
				SDL_Delay(sleepTime);
	
			manager->render();
			//update screen
			SDL_RenderPresent(renderer);
	
		}
	
}