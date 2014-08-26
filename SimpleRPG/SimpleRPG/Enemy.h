#ifndef ENEMY_H_
#define ENEMY_H_

class Enemy
{
private:
	int attack; 
	int armor;
	int health;

public:
	Enemy();
	Enemy(int, int, int);
	~Enemy();
	
	//Getters
	int getHealth() const;
	int getAttack() const;
	int getArmor() const;

	//Setters
	void setAttack(int);
	void setArmor(int);
	void setHealth(int);
};

#endif