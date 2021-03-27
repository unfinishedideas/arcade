#pragma once
#include "imports.h"

class Texture
{
	public:
		Texture(SDL_Renderer * renderer);
		~Texture();
		bool load(std::string file_path);
		bool unload();
		void render(int x, int y, SDL_Rect* clip_rect = NULL, double angle = 0.0, SDL_Point * center = NULL, SDL_RendererFlip = SDL_FLIP_NONE);
		int get_width();
		int get_height();
	private:
		SDL_Texture* _texture;
		SDL_Renderer* _tRenderer;
		int _width;
		int _height;
};
