#include "Ship.h"

const float  SPEED = 3.0f;

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Ship::update(sf::Time& elapsed)
	{
		sf::Vector2f pos = sprite_.getPosition();
		float x = pos.x;
		float y = pos.y;

		int mElapsed = elapsed.asMilliseconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	}