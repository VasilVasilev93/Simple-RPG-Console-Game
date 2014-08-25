#ifndef ENEMY_H_
#define ENEMY_H_

#include "Hero.h"

class Enemy
{
private:
	Hero hero;

	int attack; 
	int armor;
	int health;

	int damageReduction;

public:
	Enemy();
	~Enemy();
	
	//Getters
	int getHealth() const;
	int getAttack() const;
	int getArmor() const;

	//Setters
	void setAttack(int);
	void setArmor(int);
	void setHealth(int);

	//Public Methods
	void setHero(const Hero&);

	void removeHealth(int);
	
	void calculateDamage();
};

#endif