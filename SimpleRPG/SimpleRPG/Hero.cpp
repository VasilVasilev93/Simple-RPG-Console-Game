#include <iostream>
#include "Hero.h"

using std::cout;
using std::endl;

Hero::Hero() 
{

}

Hero::Hero(string newName, CharType newType)
{
	heroName = newName;
	heroClass = newType;
	equippedItem = -1;
	exp = 0;
	expToLvlUp = 30;
	level = 1;
	posX = 2;
	posY = 1;
	switch(heroClass)
	{
	case Warrior:
		health = 32;
		attack = 26;
		armor = 5;
		break;
	case Archer:
		health = 28;
		attack = 28;
		armor = 3;
		break;
	case Mage:
		health = 24;
		attack = 34;
		armor = 2;
		break;
	}
	maxHealth = health;
}

Hero::~Hero()
{

}

#pragma region Getters

void Hero::getPos(int &getX, int &getY)
{
	getX = posX;
	getY = posY;
}

string Hero::getName() const
{
	return heroName;
}

CharType Hero::getClass() const 
{
	return heroClass;
}

vector<Item> Hero::getStash() 
{
	return stash;
}

int Hero::getHealth() const
{
	return health;
}

int Hero::getAttack() const
{
	return attack;
}

int Hero::getLevel() const
{
	return level;
}

int Hero::getArmor() const
{
	return armor;
}

int Hero::getMaxHealth() const
{
	return maxHealth;
}

string Hero::getClassAsString() const
{
	string classAsString;
	switch(heroClass)
	{
	case Warrior:
		classAsString.assign("Warrior");
		break;
	case Archer:
		classAsString.assign("Archer");
		break;
	case Mage:
		classAsString.assign("Mage");
		break;
	}

	return classAsString;
}

#pragma endregion Getters for the Hero Class 

#pragma region Setters

void Hero::setPos(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
}

void Hero::resetPos()
{
	this->posX = 2;
	this->posY = 1;
}

void Hero::setHealth(int hp)
{
	this->health = hp;
}

#pragma endregion Setters for the Hero Class

#pragma region Public Methods

void Hero::pickUpItem(Item* item) 
{
	this->stash.push_back(*item);
}

void Hero::printInfo()
{
	cout << endl;
	cout << "Hero Name: " << getName() << endl;
	cout << "Hero HP: " << getHealth() << endl;
	cout << "Hero Attack Power: " << getAttack() << endl;
	cout << "Hero Level: " << getLevel() << endl;
	cout << "Hero Type: " << getClass() << endl;
	cout << "Hero Armor: " <<  getArmor() << endl;
}

void Hero::addHealth(int points)
{
	this->health += points;
}

void Hero::removeHealth(int points)
{
	if(points < 0) points = 0;
	this->health -= points;
}

void Hero::addExp(int points)
{
	if(points < 0) points = 0;
	this->exp += points;
	if(exp >= 30)
	{
		exp -= 30;
		level++;
		attack += 3;
		maxHealth += 3;
		armor += 1;
	}
}

#pragma endregion Public Methods for the Hero Class

void Hero::printStash()
{
	for(vector<Item>::iterator it1 = stash.begin(); it1 != stash.end(); it1++)
	{
		cout << it1->getName() << " " << it1->getBonus() << endl;
	}
}