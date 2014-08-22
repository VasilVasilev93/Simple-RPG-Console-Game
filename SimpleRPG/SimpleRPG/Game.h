#ifndef GAME_H_
#define GAME_H_

#include "Hero.h"
#include "Map.h"
#include "levels.h"

//start game method, clear map method, load map method, map
class Game
{
public:
	Game();
	~Game();

	void startGame();

	void loadLevel();
	void clearLevel();

	string getLvlAsString(Level) const;
	

private:
	bool game_running;

	Map map;
	Level level;

	//vector<string> map;


};

#endif