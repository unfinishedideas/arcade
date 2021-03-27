#include "imports.h"
#include "Sprite.h"

bool init(SDL_Window *& window, SDL_Renderer *& renderer);
void clean_up(SDL_Window *& window, SDL_Renderer *& renderer);
	

int main(int argc, char* args[])
{
	//SDL_Surface* surface;
	//SDL_Texture* texture;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;

	bool quit = false;

	init(window, renderer);

	Texture test(renderer);
	std::string path = "test.png";
	test.load(path);
	Sprite sprite;
	if (!sprite.load(&test))
		return 0;
	SDL_Rect rect{ 0,0,50,50 };
	sprite.setTextureRect(rect);
	sprite.setPosition(100, 100);
	//Texture test2 = test;
	// <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY <== <== <== DELETE THIS EVENTUALLY 
	//While application is running
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
		
	    //test2.render(0, 0);
		sprite.render();
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
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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

void clean_up(SDL_Window*& window, SDL_Renderer*& renderer)
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
