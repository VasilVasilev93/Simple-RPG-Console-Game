#ifndef HERO_H_
#define HERO_H_
#include <string>
#include <vector>

#include "CharType.h"
#include "Enemy.h"
//#include "Item.h"
using std::string;
using std::vector;

class Hero
{
private:
	int posX;
	int posY;

	Enemy enemy;
	string heroName;
	CharType heroClass;
	//vector<Item> stash;

	int level;
	int attack; 
	int armor;
	int health;

	int damageReduction;

public:
	// Constructor
	Hero();
	Hero(string, CharType);
	~Hero();

	// Getters
	void getPos(int&, int&);
	void resetPos();
	string getName() const;
	CharType getClass() const;
	//vector<Item> getStash();

	int getHealth() const;
	int getAttack() const;
	int getLevel() const;
	int getArmor() const;

	string getClassAsString() const;

	// Setters
	void setPos(int, int);

	void setLevel(int);
	//void setAttack(int);
	void setArmor(int);
	void setHealth(int);

	// Public Method
	//void pickUpItem(Item&);
	void printInfo() const;

	void addHealth(int);
	void removeHealth(int);

	void calculateDamage();
};

#endif