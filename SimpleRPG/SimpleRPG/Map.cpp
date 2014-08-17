#include <iostream>
#include "Map.h"
using std::cout;
using std::endl;

Map::Map(string& filePath) // not needed ???
{
	loadMap(filePath);
}

Map::~Map() 
{

}

void Map::loadMap(string& textfile)
{
	inFile.open(textfile);
	inFile >> mapHeight >> mapWidht;

	string inputLine;
	while(getline(inFile, inputLine))
	{
		map.push_back(inputLine);
	}
}

void Map::printMap()
{	
	for(unsigned row = 0; row < map.size(); row++)
	{
		cout << map[row] << endl;
	}
	Map::stopGame();
}

void Map::setHero(const Hero &hero)
{
	this->hero = hero;
}

void Map::stopGame()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		cout << "Game Over";
		hero.~Hero();
		system ("pause");
	}
}

bool Map::changeHeroPos(int movX, int movY) // movX = -1 || 0 || 1		movY = -1 || 0 || 1
{
	int heroX, heroY;
	this->hero.getPos(&heroX, &heroY);
	heroX += movX;
	heroY += movY;

	if(map[heroX][heroY] == ' ')
	{
		map[heroX - movX][heroY - movY] = ' ';
		map[heroX][heroY] = '@';
	}
	else if(map[heroX][heroY] == '$')
	{
		map[heroX - movX][heroY - movY] = ' ';
		this->hero.setHealth(rand() % 60 + 99); // create method to calculate damage
		map[heroX][heroY] = '@';
	}
	else if(map[heroX][heroY] == '&')
	{
		map[heroX - movX][heroY - movY] = ' ';
		this->hero.setHealth(rand() % (50-30 +1) + 30); // create method to calculate damage
		map[heroX][heroY] = '@';
	}
	else if(map[heroX][heroY] == '%')
	{
		this->hero.setHealth(100);
		system("cls");
		cout << "gratZ!" << endl;
	}
	else if(map[heroX][heroY] == '*')
	{
		this->hero.addHealth(5);
		map[heroX - movX][heroY - movY] = ' ';
		map[heroX][heroY] = '@';
	}
	else
	{
		return false;
	}

	this->hero.setPos(heroX, heroY);
	return true;
}

void Map::move()
{
	if (GetAsyncKeyState(VK_UP))
	{
		changeHeroPos(0, 1);
	}
	else if(GetAsyncKeyState(VK_DOWN))
	{
		changeHeroPos(0, -1);
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		changeHeroPos(1, 0);
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		changeHeroPos(-1, 0);
	}

	// TODO: Add logic for a pressed ESC button
}