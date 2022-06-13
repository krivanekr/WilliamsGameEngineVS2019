#pragma once

#include "Engine/GameEngine.h"

class Meteor : public GameObject
{
public:
	// Creates our Meteor
	Meteor(sf::Vector2f pos);

	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);
private:
	sf::Sprite sprite_;
	float SPEED = 0.5 + rand() % (100);
};

typedef std::shared_ptr<Meteor> MeteorPtr;