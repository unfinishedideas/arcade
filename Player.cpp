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

void Player::update(float dt)
{
	posX = int(float(posX + .223*dt));
	posY = int(float(posY + .34 * dt));
	if (posX > SCREEN_WIDTH)
		posX = -50;
	if (posY > SCREEN_HEIGHT)
		posY = -50;
	_sprite.setPosition(posX, posY);
}