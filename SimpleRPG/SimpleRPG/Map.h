#ifndef MAP_H_
#define MAP_H_
#include "windows.h"
#include <string>
#include "Game.h"
#include "levels.h"
//#include <vector>
#include <fstream>

#include "Hero.h"
using std::string;
using std::vector;

class Map
{
private:
	bool game_running;
	int mapHeight;
	int mapWidht;
	Hero hero;

	Level level;

	std::ifstream inFile;
	vector<string> map;

	

public:
	//Map(string);
	~Map();

	void clearMap();
	//void nextLevel();
	void loadMap(string);

	void setHero(const Hero&);
	bool changeHeroPos(int, int);

	void move();

	void printMap();

	//string getLevelAsString(Level) const;
};

#endif