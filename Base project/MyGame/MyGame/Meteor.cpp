#include "Meteor.h"
#include "Explosion.h"
#include "GameScene.h"

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

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
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
		otherGameObject.makeDead();
		ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
	    GAME.getCurrentScene().addGameObject(explosion);
		GameScene& scene = (GameScene&)GAME.getCurrentScene();

		scene.increaseScore();
	}
	if (otherGameObject.hasTag("ship"))
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();

		scene.decreaseLives();
		int lives;
		lives =	scene.getLives();
		if (lives = 0)
		{
			otherGameObject.makeDead();
			ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
			GAME.getCurrentScene().addGameObject(explosion);
		}
	}
	makeDead();
}