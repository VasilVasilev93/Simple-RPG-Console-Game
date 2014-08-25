#include "Enemy.h"

Enemy::Enemy()
{

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

#pragma region Public Methods

void Enemy::setHero(const Hero &hero)
{
	this->hero = hero;
}

void Enemy::removeHealth(int points)
{
	this->health -= points;
}

void Enemy::calculateDamage()
{
	damageReduction = (int)(this->hero.getAttack()*(armor*10))/100;
	removeHealth(this->hero.getAttack() - damageReduction);
}

#pragma endregion Public Methods for the Enemy Class


