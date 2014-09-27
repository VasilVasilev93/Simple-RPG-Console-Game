#ifndef ARMOR_H_
#define ARMOR_H_

#include <string>
#include "Item.h"

class Armor: public Item
{
private:

public:
	Armor();
	Armor(std::string name, int bonus) : Item(name, bonus)
	{
		this->name = name;
		this->bonus = bonus;
	}

	virtual std::string getName()
	{
		//std::cout << "Name: ";
		return name;
	}

	virtual int getBonus()
	{
		//std::cout << "Armor bonus: ";
		return bonus;
	}
};
#endif
