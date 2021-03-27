#include "Player.h"

Player::Player()
{
	posX = 0;
	posY = 0;
	_isLoaded = false;
}

Player::~Player()
{
}

void Player::load(Texture* text)
{
	_sprite.setTexture(text);
	_sprite.setTextureRect(SDL_Rect{ 0,0,50,50 });
	_sprite.setPosition(posX, posY);
	_isLoaded = true;
}

void Player::render() 
{
	if(_isLoaded)
		_sprite.render();
}