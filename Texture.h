#pragma once
#include "imports.h"
#include <string>
#include <iostream>

class Texture
{
	public:
		Texture(SDL_Renderer * renderer);
		~Texture();
		bool load(std::string file_path);
		bool unload();
		void render(int x, int y, SDL_Rect* clip_rect = NULL, double zoom = 1.0, double angle = 0.0, SDL_Point * center = NULL, SDL_RendererFlip = SDL_FLIP_NONE);
		void setBlendMode(SDL_BlendMode blend);
		void setAlpha(Uint8 alpha);
		void setColor(Uint8 red, Uint8 green, Uint8 blue);
		int get_width();
		int get_height();
	private:
		SDL_Texture* _texture;
		SDL_Renderer* _tRenderer;
		int _width;
		int _height;
};
