#include "Texture.h"

Texture::Texture(SDL_Renderer * renderer)
{
	_texture = NULL;
	_width = 0;
	_height = 0;
	_tRenderer = renderer;
}

Texture::~Texture()
{
	// free up the memory used for the texture
	if (unload() == false)
		std::cout << "\n~Texture() failed to unload properly!";
}

//bool Texture::load(SDL_Renderer * renderer, std::string file_path)
bool Texture::load(std::string file_path)
{
	//bool success = true;		// used to determine success of function
	//SDL_Surface * image;		// used to load the image
	//
	//// attempt image load
	//image = IMG_Load(file_path);

	//if (!image)
	//{
	//	success = false;
	//	std::cout << "IMG_Load failed!";
	//}
	//else
	//{
	//	//Set the chroma key value
	//	//SDL_SetColorKey(image, SDL_TRUE, CHROMA_VALUE);
	//}
	//
	//if (success)
	//{
	//_texture = SDL_CreateTextureFromSurface(renderer, image);

	//	if (_texture == NULL)
	//		success = false;
	//	else
	//	{
	//		std::cout << "success";
	//	}
	//}

	//return success;

	//Get rid of preexisting texture
	unload();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(file_path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", file_path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(_tRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", file_path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			_width = loadedSurface->w;
			_height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	_texture = newTexture;
	return _texture != NULL;
}

bool Texture::unload()
{
	bool success = true;
	SDL_ClearError();

	if (!_texture)
		SDL_DestroyTexture(_texture);

	// lets use either SDL's logging or spdlog for our logging so we can set modes and whatnot
	if (strcmp(SDL_GetError(), "Invalid texture") == 0)
		success = false;

	return success;
}

//void Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip_rect)
void Texture::render(int x, int y, SDL_Rect* clip_rect)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, _width, _height };

	//Set clip rendering dimensions
	if (clip_rect != NULL)
	{
		renderQuad.w = clip_rect->w;
		renderQuad.h = clip_rect->h;
	}

	//Render to screen
	SDL_RenderCopy(_tRenderer, _texture, clip_rect, &renderQuad);

	return;
}

int Texture::get_width()
{
	return _width;
}

int Texture::get_height()
{
	return _height;
}
