#ifndef MAP_H_
#define MAP_H_
#include "windows.h"
#include <string>
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

	std::ifstream inFile;
	vector<string> map;

	void loadMap(string);

public:
	Map(string);
	~Map();

	void printMap(); // may be deprecated

	void setHero(const Hero&);
	bool changeHeroPos(int, int);

	void move();
};

#endif