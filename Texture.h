#pragma once
#include "imports.h"

class Texture
{
	public:
		Texture(SDL_Renderer * trenderer);
		~Texture();
		bool load(std::string file_path);
		bool unload();
		void render(int x, int y, SDL_Rect* clip_rect = NULL);
		int get_width();
		int get_height();
	private:
		SDL_Texture* _texture;
		SDL_Renderer* _tRenderer;
		int _width;
		int _height;
};
