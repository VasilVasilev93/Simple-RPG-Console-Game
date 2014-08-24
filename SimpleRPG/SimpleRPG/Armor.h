#ifndef ARMOR_H_
#define ARMOR_H_

#include <string>
#include "Item.h"

class Armor: public Item
{
private:
	int bonusArmor;

public:
	Armor();
	Armor(std::string newName, int newBonus)
	{
		name = newName;
		bonusArmor = newBonus;
	}
	~Armor();

	virtual std::string getName()
	{
		std::string result = "Armor: " + name;
		return result;
	}
	int getBonusArmor()
	{
		return bonusArmor;
	}

};
#endif
