#include "GameScene.h"

#include "monstre.h"
#include "MeteorSpawner.h"
#include "Score.h"
#include "Lives.h"
#include "GameOverScene.h"

GameScene::GameScene() 
{
	MonstrePtr monstre = std::make_shared<Monstre>();
	addGameObject(monstre);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);

	LivesPtr lives = std::make_shared<Lives>(sf::Vector2f(300.0f, 10.0f));
	addGameObject(lives);
}

int GameScene::getScore()
{
	return score_;
}

void GameScene::increaseScore()
{
	score_ = score_ + 10;
}

int GameScene::getLives()
{
	return lives_;
}

void GameScene::decreaseLives()
{
	--lives_;

	if (lives_ == 0)
	{
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}
}/*
sf::Vector2f GameScene::getGameObject(std::string tag)
{
	int currentObject = 0;
	for (auto& gameObject : gameObjects_)
	{
		if (gameObject->hasTag(tag))
		{
			sf::Vector2f pos = gameObject;
			return pos;
		}
		currentObject++;
	}
}*/