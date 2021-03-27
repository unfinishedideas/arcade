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
	_sprite.setFlip(SDL_FLIP_HORIZONTAL);
	_isLoaded = true;
}

void Player::render() 
{
	if(_isLoaded)
		_sprite.render();
}

void Player::update(float dt)
{
	posX = int(float(posX + .123*dt));
	posY = int(float(posY + .24 * dt));
	if (posX > SCREEN_WIDTH)
		posX = -50;
	if (posY > SCREEN_HEIGHT)
		posY = -50;
	_sprite.setPosition(posX, posY);
	double angle = _sprite.getAngle();
	angle = angle + 0.1 * dt;
	_sprite.setAngle(angle);
	double zoom = _sprite.getZoom();
	if (zoom < 4)
		zoom = zoom + 0.001 * dt;
	else
		zoom = 0.3;
	_sprite.setZoom(zoom);
	_sprite.setAngle(angle);
}