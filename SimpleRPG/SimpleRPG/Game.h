#ifndef GAME_H_
#define GAME_H_

#include "Map.h"
#include "levels.h"


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

	int currentLevel;

	Map map;
	Level level;
};

#endif