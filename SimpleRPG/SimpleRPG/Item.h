#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item
{
protected:
	std::string name;
	int bonus;
	int type;

public:
	Item();
	Item(std::string name, int bonus)
	{
		this->name = name;
		this->bonus = bonus;
	}
	virtual ~Item(){}

	virtual std::string getName()
	{
		return name;
	}

	virtual int getBonus()
	{
		return bonus;
	}
};
#endif
