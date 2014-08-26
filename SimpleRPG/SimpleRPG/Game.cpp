#include <iostream>
#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::startGame()
{
	game_running = true;
	currentLevel = 0;
	map.createHero("B.Borisov", Warrior);
	map.createEnemy(12,1,18);
	
	while(game_running && map.game_running)
	{
		loadLevel();
		if(game_running)
			map.move();
	}
}

string Game::getLvlAsString(Level newLevel) const
{
	string levelAsString;
	switch(newLevel)
	{
	case Level1:
		levelAsString.assign("Level1.txt");
		break;
	case Level2:
		levelAsString.assign("Level2.txt");
		break;
	case Level3:
		levelAsString.assign("Level3.txt");
		break;
	case Level4:
		levelAsString.assign("Level4.txt");
		break;
	}

	return levelAsString;
}

void Game::clearLevel()
{
	this->map.clearMap();
}

void Game::loadLevel()
{
	Level l;
	if(currentLevel <= 3)
	{
		l = (Level)currentLevel;

		map.loadMap(getLvlAsString(l));
		currentLevel++;
	}
	else
	{
		game_running = false;
		std::cout << "You finished the game!";
	}
}
