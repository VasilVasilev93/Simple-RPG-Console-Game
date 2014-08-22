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
}

string Game::getLvlAsString(Level newLevel) const
{
	string levelAsString;
	switch(newLevel)
	{
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
	int count = 0;
	if(count <= 2)
	{
		l = (Level)count;

		map.loadMap(getLvlAsString(l));
		count++;
		//this->setHero(hero);
		//this->move();
	}
}
