#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item
{
protected:
	std::string name;

public:
	Item();
	~Item();

	virtual std::string getName()
	{
		return name;
	}
};
#endif
