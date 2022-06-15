#pragma once

#include "Engine/GameEngine.h"

class Monstre : public GameObject
{
public:
	//Creates our Monstre.
	Monstre();

	//Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	//sf::Vector2f getPosition(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
	int fireTimer_ = 0;
	int fireTimer2_ = 0;
	int fireTimer3_ = 0;
};

typedef std::shared_ptr<Monstre> MonstrePtr;