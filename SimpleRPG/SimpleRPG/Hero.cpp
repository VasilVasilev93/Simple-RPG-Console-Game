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

vector<ItemType> Hero::getStash() 
{
	return stash;
}

int Hero::getHealth() const
{
	return health;
}

double Hero::getAttack() const
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

// TODO: Add setters for level, attack and armor

#pragma endregion Setters for the Hero Class

#pragma region Public Methods

void Hero::pickUpItem(ItemType& item) 
{
	this->stash.push_back(item);
}

void Hero::printInfo() const
{
	cout << endl;
	cout << "Hero Name: " << heroName << endl;
	cout << "Hero HP: " << health << endl;
	cout << "Hero Attack Power: " << attack << endl;
	cout << "Hero Level: " << level << endl;
	cout << "Hero Type: " << getClassAsString() << endl;
	cout << "Hero Armor: " <<  armor << endl;
	cout << "Hero Inventory: " << endl;
}

void Hero::addHealth(int points)
{
	this->health += points;
}

void Hero::removeHealth(int points)
{
	this->health -= points;
}
//todo: enemy class?
void Hero::calculateDamage()
{
	// damageReduction = (enemyAttack*(armor*10))/100)
	//need enemy class? 
	//removeHealth(enemyAttack - damageReduction)
}

#pragma endregion Public Methods for the Hero Class
