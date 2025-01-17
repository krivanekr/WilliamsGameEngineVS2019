#pragma once

#include "Engine/GameEngine.h"
#include "Meteor.h"

class MeteorSpawner : public GameObject
{
public:
	void update(sf::Time& elpased);
private:
	int timer_ = 500;
};

typedef std::shared_ptr<MeteorSpawner>  MeteorSpawnerPtr;