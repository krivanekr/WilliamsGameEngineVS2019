#include "Ship.h"

const float  SPEED = 1.5f;

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

		int msElapsed = elapsed.asMilliseconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pos.y > 20)	y -= SPEED * msElapsed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pos.y < 625)	y += SPEED * msElapsed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && pos.x > 20)	x -= SPEED * msElapsed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && pos.x < 815)	x += SPEED * msElapsed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pos.y > 30)	y -= SPEED * msElapsed * 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pos.y < 615)	y += SPEED * msElapsed * 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && pos.x > 50)	x -= SPEED * msElapsed * 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && pos.x < 805)	x += SPEED * msElapsed * 2;

		sprite_.setPosition(sf::Vector2f(x, y));
	}