#include <iostream>
#include "Map.h"
//#include "Armor.h"

using std::cout;
using std::endl;


Map::~Map()
{

}

void Map::clearMap()
{
	map.clear();
}

void Map::loadMap(string textfile)
{
	inFile.open(textfile);
	inFile >> mapHeight >> mapWidht;
	
	clearMap();

	string inputLine;
	while(getline(inFile, inputLine))
	{
		map.push_back(inputLine);
	}
	inFile.close();

	printMap();
}

void Map::printMap()
{

	for(vector<string>::iterator row = map.begin(); row != map.end(); ++row)
	{
		cout << *row << endl;
	}
}

/*void Map::generateItem()
{
	int bonus = 0;

	this->hero.pickUpItem(new Armor("Somename", bonus));
}*/

void Map::setHero(const Hero &hero)
{
	this->hero = hero;
}

void Map::createHero(string newName, CharType newType)
{
	Hero newHero(newName, newType);
	setHero(newHero);
}

bool Map::changeHeroPos(int movX, int movY) // movX = -1 || 0 || 1		movY = -1 || 0 || 1
{
	int heroX, heroY;
	this->hero.getPos(heroX, heroY);
	heroX += movX; 
	heroY += movY;

	if(map[heroX][heroY] == ' ')
	{
		map[heroX - movX][heroY - movY] = ' ';
		map[heroX][heroY] = '@';
		
		system ("cls");
		printMap();
		system("pause");

	}
	else if(map[heroX][heroY] == '$')
	{
		map[heroX - movX][heroY - movY] = ' ';
		this->hero.calculateDamage();
		this->hero.setHealth(rand() % 60 + 99); // create method to calculate damage
		map[heroX][heroY] = '@';
		system ("cls");
		printMap();
		system("pause");
	}
	else if(map[heroX][heroY] == '&')
	{
		map[heroX - movX][heroY - movY] = ' ';
		this->hero.calculateDamage();
		this->hero.setHealth(rand() % (50-30 +1) + 30); // create method to calculate damage
		map[heroX][heroY] = '@';
		system ("cls");
		printMap();
		system("pause");
	}
	else if(map[heroX][heroY] == '%')
	{
		this->hero.setHealth(100);
		system("cls");
		
		level_ended = true;
	}
	else if(map[heroX][heroY] == '*')
	{
		this->hero.addHealth(5);
		map[heroX - movX][heroY - movY] = ' ';
		map[heroX][heroY] = '@';
		system ("cls");
		printMap();
		system("pause");
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
	game_running = true;
	level_ended = false;
	this->hero.resetPos();
	while(!level_ended && game_running)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			changeHeroPos(-1, 0);
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			changeHeroPos(1, 0);	
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			changeHeroPos(0, 1);
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			changeHeroPos(0, -1);
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			cout << "Game Over" << endl;
			game_running = false;
			break;
		}
	}
}