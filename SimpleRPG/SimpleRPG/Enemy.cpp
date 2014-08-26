#include "Enemy.h"

#include <iostream>

Enemy::Enemy()
{

}

Enemy::Enemy(int newAttack, int newArmor, int newHealth)
{
	attack = newAttack;
	armor = newArmor;
	health = newHealth;
}

Enemy::~Enemy()
{

}

#pragma region Getters

int Enemy::getArmor() const
{
	return armor;
}

int Enemy::getAttack() const
{
	return attack;
}

int Enemy::getHealth() const
{
	return health;
}

#pragma endregion Getters for the Enemy Class

#pragma region Setters

void Enemy::setAttack(int newAttack)
{
	this->attack = newAttack;
}

void Enemy::setArmor(int newArmor)
{
	this->armor = newArmor;
}

void Enemy::setHealth(int newHealth)
{
	this->health = newHealth;
}

#pragma endregion Setters for the Enemy Class