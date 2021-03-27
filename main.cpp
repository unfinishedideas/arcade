#include "imports.h"
#include "Sprite.h"
#include "Player.h"

const float FPS = 60; //frames per second


bool init(SDL_Window *& window, SDL_Renderer *& renderer);
void clean_up(SDL_Window * window, SDL_Renderer * renderer);
	

int main(int argc, char* args[])
{
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;

	bool quit = false;

	init(window, renderer);

	Texture test(renderer);
	std::string path = "test.png";
	test.load(path);
	
	Player joe;
	//joe.load(&test);
	VisibleObject* vis = &joe;
	vis->load(&test);
	// <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY 
	//While application is running
	float prevTime = float(SDL_GetTicks());
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(renderer);
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		vis->processInput(currentKeyStates);
		float currTime = float(SDL_GetTicks());
		if (currTime - prevTime < 0)
			continue;
		vis->update(currTime - prevTime);
		float t = currTime - prevTime;
		prevTime = currTime;
		int sleepTime = int(1000/FPS- t); //cap framerate at FPS 
		if (sleepTime > 0)
			SDL_Delay(sleepTime);
		vis->render();
		
		//Update screen
		SDL_RenderPresent(renderer);

	}
	// <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY 

	// Deallocate SDL
	clean_up(window, renderer);

	return 0;
}

bool init(SDL_Window*& window, SDL_Renderer*& renderer)
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
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

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

	return success;
}

void clean_up(SDL_Window* window, SDL_Renderer* renderer)
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

	return;
}
