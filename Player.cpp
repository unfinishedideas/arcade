#include "Player.h"

Player::Player() : VisibleObject("player")
{
	
	_isLoaded = false;
    frameTime = 0.f;
}

Player::~Player()
{
  
}

void Player::load(Texture* text)
{
   // pos = floatVec(130.f, 50.f);
    _sprite.setTexture(text);
	_sprite.setTextureRect(SDL_Rect{ 0,0,95,160 });
	_sprite.setPosition(pos);
    _sprite.setColor(0,255,0);
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
        vel.y = -.5;
    }
    if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
     //   velX = 0;
        vel.y = .5;
    }
    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        vel.x = -.5;
      //  velY = 0;
    }
    if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        vel.x = .5;
      //  velY = 0;
    }
    
    
}
void Player::update(float dt)
{
        //posX = posX + dt*velX;
        //posY = posY + dt*velY;
    pos = pos + dt * vel;
    _sprite.setPosition(pos);
    vel = floatVec(0.f, 0.f);
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

void Player::setPos(floatVec _pos)
{
    pos = _pos;
}