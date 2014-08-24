#ifndef MAP_H_
#define MAP_H_
#include "windows.h"
#include <string>
#include "levels.h"
#include <fstream>

#include "Hero.h"

using std::string;
using std::vector;

class Map
{
private:
	bool level_ended;
	int mapHeight;
	int mapWidht;
	Hero hero;

	Level level;

	std::ifstream inFile;
	vector<string> map;

	void generateItem();

public:
	bool game_running;

	~Map();

	void clearMap();
	void loadMap(string);

	void setHero(const Hero&);
	void createHero(string, CharType);
	bool changeHeroPos(int, int);

	void move();

	void printMap();
};

#endif