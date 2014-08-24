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
	Weapon(std::string newName, int newBonus)
	{
		name = newName;
		bonusAttack = newBonus;
	}
	~Weapon();

	virtual std::string getName()
	{
		std::string result = "Attack: " + name;
		return result;
	}
	int getBonusAttack()
	{
		return bonusAttack;
	}

};
#endif
