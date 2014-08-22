#include <iostream>
#include "Map.h"

using std::cout;
using std::endl;

/*Map::Map(string filePath)
{
	loadMap(filePath);
}*/

Map::~Map()
{

}

/*string Map::getLevelAsString(Level newLevel) const
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
}*/

void Map::clearMap()
{
	//Map::~Map();
	map.clear();
}

void Map::loadMap(string textfile)
{
	inFile.open(textfile);
	inFile >> mapHeight >> mapWidht;
	
	clearMap();
	//vector<string>(map).swap(map);

	string inputLine;
	while(getline(inFile, inputLine))
	{
		map.push_back(inputLine);
	}
	
	printMap();
	game_running = true;
}

void Map::printMap()
{

	for(vector<string>::iterator row = map.begin(); row != map.end(); ++row)
	{
		cout << *row << endl;
	}
}

/*void Map::nextLevel()
{
	Level l;
	int count = 0;
	if(count <= 2)
	{
		l = (Level)count;
		//loadMap(getLevelAsString(l));
		
		
		Map::Map(getLevelAsString(l));
		count++;
		this->setHero(hero);
		this->move();
	}
	
}*/

void Map::setHero(const Hero &hero)
{
	this->hero = hero;
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
		cout << "gratZ!" << endl;
		game_running = false;
		this->hero.resetPos();
		//game.loadlevel()..?
		//nextLevel();
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
	//game_running = true;
	while(game_running = true)
	{
		//if( )break;
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
			hero.~Hero();
			break;
		}
	}
		

}