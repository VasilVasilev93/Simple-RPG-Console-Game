#ifndef MAP_H_
#define MAP_H_
#include "windows.h"
#include <string>
#include "levels.h"
#include <fstream>

#include "Enemy.h"
#include "Hero.h"

using std::string;
using std::vector;

class Map
{
private:
	bool level_ended;
	int mapHeight;
	int mapWidht;

	Level level;

	std::ifstream inFile;
	vector<string> map;

	void generateItem();
	string randomItemName(int, int);
	string getItemAsString(int) const;

	void calculateDmg();

	void saveHeroStatus(string, string, int, int, int, int, int, string, std::vector<Item>);

public:
	bool game_running;

	Hero hero;
	Enemy enemy;

	~Map();

	void clearMap();
	void loadMap(string);

	void setHero(const Hero&);
	void createHero(string, CharType);
	void createEnemy(int, int, int);
	bool changeHeroPos(int, int);

	void move();

	void printMap();
};

#endif