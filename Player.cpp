#include "Player.h"

Player::Player() : VisibleObject("player")
{
	posX = 0.f;
	posY = 0.f;
	velX = 0.f;
	velY = 0.f;
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

void Player::processInput(const Uint8* currentKeyStates)
{
    if (currentKeyStates[SDL_SCANCODE_UP])
    {
      //  velX = 0;
        velY = -.5;
    }
    if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
     //   velX = 0;
        velY = .5;
    }
    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        velX = -.5;
      //  velY = 0;
    }
    if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        velX = .5;
      //  velY = 0;
    }
    
    
}
void Player::update(float dt)
{
        posX = posX + dt*velX;
        posY = posY + dt*velY;
        _sprite.setPosition(posX, posY);
        velX = 0;
        velY = 0;
   
}