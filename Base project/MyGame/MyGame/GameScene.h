#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();

  // Get the current score
  int getScore();

  // Increase the score
  void increaseScore();

  // Get the current score
  int getLives();

  // Increase the score
  void decreaseLives();
  
private:
	int score_ = 0;

	int lives_ = 3;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
