#include "Player.h"

Player::Player() : VisibleObject("player")
{
	posX = 0.f;
	posY = 0.f;
	velX = 0.f;
	velY = 0.f;
	_isLoaded = false;
    frameTime = 0.f;
}

Player::~Player()
{
  
}

void Player::load(Texture* text)
{
	_sprite.setTexture(text);
	_sprite.setTextureRect(SDL_Rect{ 0,0,95,160 });
	_sprite.setPosition(posX, posY);
    _sprite.setColor(255,255,0);
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
       frameTime = frameTime + dt;
        if (frameTime > 800)
        {
            SDL_Rect rect = _sprite.getTextureRect();
            rect.x +=95;
            if (rect.x > 95 * 7)
                rect.x = 0;
            _sprite.setTextureRect(rect);
            frameTime = 0;
        }
      // if (posX > 500)
        //    this->setDead();
}

void Player::setPos(float x, float y)
{
    posX = x;
    posY = y;
}