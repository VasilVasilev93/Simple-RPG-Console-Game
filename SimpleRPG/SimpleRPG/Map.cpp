#include <iostream>
#include <stdlib.h>

#include "Map.h"
#include "Armor.h"
#include "Weapon.h"


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
	cout << "Hero name: " << this->hero.getName() << endl;
	cout << "Hero class: " << this->hero.getClass() << endl;
	cout << "Hero HP: " << this->hero.getHealth() << endl;
	cout << "Hero LVL: " << this->hero.getLevel() << endl;
}

string Map::getItemAsString(int typeNumber) const
{
	string itemAsString;
	switch(typeNumber)
	{
	case 1:
		itemAsString.assign("The Nutcracker");
		break;
	case 2:
		itemAsString.assign("Eyepoker");
		break;
	case 3:
		itemAsString.assign("The Perforator");
		break;
	case 4:
		itemAsString.assign("Dragon Shield");
		break;
	case 5:
		itemAsString.assign("Boobs Of Steal!");
		break;
	case 6:
		itemAsString.assign("Party Hat");
		break;
	}

	return itemAsString;
}

string Map::randomItemName(int x, int y)
{
	int itemNumber = rand() %x + y;
	return getItemAsString(itemNumber);
}

void Map::generateItem()
{
	std::string itemName;

	int bonus = 0;

	int randomItem = rand() %2 + 1;
	switch(randomItem)
	{
	case 1:
		itemName.assign(randomItemName(3, 4));
		bonus = 1;
		this->hero.pickUpItem(new Armor(itemName, bonus));
		cout << "You have obtained new Armor: " << itemName << " and you gained " << bonus << " bonus armor!" << endl;
		break;
	case 2:
		bonus = rand() %3 + 1; 
		itemName.assign(randomItemName(3, 1));
		this->hero.pickUpItem(new Weapon(itemName, bonus));
		cout << "You have obtained new Weapon : " << itemName << " and you gained " << bonus << " bonus attack!" << endl;
		break;
	}
	
}

void Map::setHero(const Hero &hero)
{
	this->hero = hero;
}

void Map::createHero(string newName, CharType newType)
{
	Hero newHero(newName, newType);
	setHero(newHero);
}

void Map::createEnemy(int attack, int armor, int health)
{
	Enemy newEnemy(attack, armor, health);
	this->enemy = newEnemy;
}

void Map::calculateDmg()
{
	//damageReduction = (int)(this->hero.getAttack()*(armor*10))/100;
	//removeHealth(this->hero.getAttack() - damageReduction);
	//damageReduction = (int)(this->enemy.getAttack()*(armor*10))/100;
	//removeHealth(this->enemy.getAttack() - damageReduction);

	int dmgRedHero = (int) (this->hero.getArmor() / 10);
	int dmgRedEnemy = (int) (this->enemy.getArmor() / 10);

	int enemyHealth = enemy.getHealth();
	while(enemyHealth > 0)
	{
		int heroDmgTaken = enemy.getAttack() - dmgRedHero;
		this->hero.removeHealth(heroDmgTaken);
		this->hero.addExp(heroDmgTaken);

		int enemyDmgTaken = hero.getAttack() - dmgRedEnemy;
		if(enemyDmgTaken < 0)
		{
			enemyDmgTaken = 0;
			break;
		}
		enemyHealth -= enemyDmgTaken;
	}
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
		map[heroX][heroY] = '@';
		system ("cls");
		printMap();
		generateItem();
		system("pause");
	}
	else if(map[heroX][heroY] == '&')
	{
		map[heroX - movX][heroY - movY] = ' ';
		this->calculateDmg();
		map[heroX][heroY] = '@';
		system ("cls");
		printMap();
		system("pause");
	}
	else if(map[heroX][heroY] == '%')
	{
		system("cls");
		level_ended = true;
		hero.setHealth(this->hero.getMaxHealth());
	}
	else if(map[heroX][heroY] == '*')
	{
		this->hero.addHealth(15);
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
	if(this->hero.getHealth() > 0)
	{
		this->hero.setPos(heroX, heroY);
		return true;
	}
}

void Map::move()
{
	game_running = true;
	level_ended = false;
	this->hero.resetPos();
	while(!level_ended && game_running)
	{
		if(this->hero.getHealth() <= 0)
		{
			game_running = false;
			cout << "Hero dead, game over";
			break;
		}
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
		else if(GetAsyncKeyState(VK_END))
		{
			this->hero.printStash();
			system("pause");
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			cout << "Game Over" << endl;
			game_running = false;
			break;
		}
	}
}