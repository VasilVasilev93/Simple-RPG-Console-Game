#ifndef GAME_H_
#define GAME_H_

#include "Hero.h"
#include "Map.h"

//start game method, clear map method, load map method, map
class Game
{
public:
	Game();
	~Game();


	void loadLevel(string);
	void clearLevel();
	void nextLevel();
	

private:
	bool game_running;

	Map level;
	
	vector<string> map;


};

#endif