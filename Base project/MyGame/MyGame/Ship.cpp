#include "Ship.h"

#include <memory>
#include "Laser.h"


Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
	assignTag("ship");
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Ship::update(sf::Time& elapsed)
	{

	    const float SPEED = 1.5f;
	    const int FIRE_DELAY = 30;
	    sf::FloatRect bounds = sprite_.getGlobalBounds();
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

		if (fireTimer_ > 0)
		{
			fireTimer_ -= msElapsed;
		}
		if (fireTimer2_ > 0)
		{
			fireTimer2_ -= msElapsed;
		}
		if (fireTimer3_ > 0)
		{
			fireTimer3_ -= msElapsed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && fireTimer_ <= 0)
		{
            // Bottom Gun

			fireTimer_ = FIRE_DELAY;

			float laserX = x - 90 + bounds.width;
			float laserY = y + 70 + (bounds.height / 2.0f);

			LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
			GAME.getCurrentScene().addGameObject(laser);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && fireTimer2_ <= 0)
		{
			// Middle Gun 

			fireTimer2_ = FIRE_DELAY;
			
			float laserX = x - 50 + bounds.width;
			float laserY = y + (bounds.height / 2.0f);

			LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
			GAME.getCurrentScene().addGameObject(laser);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && fireTimer3_ <= 0)
		{
			// Top Gun

			fireTimer3_ = FIRE_DELAY;

			float laserX = x - 90 + bounds.width;
			float laserY = y - 70 + (bounds.height / 2.0f);

			LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
			GAME.getCurrentScene().addGameObject(laser);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && fireTimer_ <= 0 && fireTimer2_ <= 0 && fireTimer3_ <= 0)
		{

			// Top Gun
			fireTimer_ = FIRE_DELAY;

			float laser1X = x - 90 + bounds.width;
			float laser1Y = y + 70 + (bounds.height / 2.0f);

			LaserPtr laser1 = std::make_shared<Laser>(sf::Vector2f(laser1X, laser1Y));
			GAME.getCurrentScene().addGameObject(laser1);

			// Middle Gun

			fireTimer2_ = FIRE_DELAY;

			float laser2X = x - 50 + bounds.width;
			float laser2Y = y + (bounds.height / 2.0f);

			LaserPtr laser2 = std::make_shared<Laser>(sf::Vector2f(laser2X, laser2Y));
			GAME.getCurrentScene().addGameObject(laser2);

			//Bottom Gun

			fireTimer3_ = FIRE_DELAY;

			float laser3X = x - 90 + bounds.width;
			float laser3Y = y - 70 + (bounds.height / 2.0f);

			LaserPtr laser3 = std::make_shared<Laser>(sf::Vector2f(laser3X, laser3Y));
			GAME.getCurrentScene().addGameObject(laser3);
		}
	}

	sf::FloatRect Ship::getCollisionRect()
	{
		return sprite_.getGlobalBounds();
	}