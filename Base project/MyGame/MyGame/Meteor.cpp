#include "Meteor.h"
#include "Explosion.h"
#include "GameScene.h"
#include "Monstre.h"
#include <windows.h>

const float SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
	setCollisionCheckEnabled(true);
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.y > sprite_.getGlobalBounds().height * 17)
	{
		makeDead();
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
		int lives;
		lives = scene.getLives();
		lives--;
		if (lives == 0)
		{
			makeDead();
			ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
			GAME.getCurrentScene().addGameObject(explosion);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		int myX;
		int myY;
		GameObject myobject;

		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		myobject.p = scene.getGameObject("Monstre");









		if (pos.x > )
		sprite_.setPosition(sf::)
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x, SPEED * msElapsed + pos.y));
	}
}

sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		
	}
	else if (otherGameObject.hasTag("Monstre"))
	{
		
		makeDead();
		ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
		GAME.getCurrentScene().addGameObject(explosion);
		GameScene& scene = (GameScene&)GAME.getCurrentScene();

		scene.increaseScore();
	}
}