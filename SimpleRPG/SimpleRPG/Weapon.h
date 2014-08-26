#ifndef WEAPON_H_
#define WEAPON_H_

#include <string>
#include "Item.h"

class Weapon: public Item
{
private:
	int bonusAttack;

public:
	Weapon();
	Weapon(std::string name, int bonus) : Item(name, bonus)
	{
		this->name = name;
		this->bonus = bonus;
	}

	virtual std::string getName()
	{
		std::string result = "Attack: " + name;
		return result;
	}

	virtual std::string getType()
	{
		return "Weapon";
	}
};
#endif
