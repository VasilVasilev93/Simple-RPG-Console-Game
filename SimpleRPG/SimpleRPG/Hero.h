#ifndef HERO_H_
#define HERO_H_
#include <string>
#include <vector>

#include "CharType.h"
#include "ItemType.h"
using std::string;
using std::vector;

class Hero
{
private:
	int posX;
	int posY;

	string heroName;
	CharType heroClass;
	vector<ItemType> stash;

	int level;
	double attack; 
	int armor;
	int health;

public:
	// Constructor
	Hero();
	Hero(string&, CharType&);
	~Hero();

	// Getters
	void getPos(int*, int*);
	string getName() const;
	CharType getClass() const;
	vector<ItemType> getStash();

	int getHealth() const;
	double getAttack() const;
	int getLevel() const;
	int getArmor() const;

	string getClassAsString() const;

	// Setters
	void setPos(int, int);

	void setLevel(int);
	void setAttack(double);
	void setArmor(int);
	void setHealth(int);

	// Public Method
	void pickUpItem(ItemType&);
	void printInfo() const;

	void addHealth(int);
	void removeHealth(int);
};

#endif