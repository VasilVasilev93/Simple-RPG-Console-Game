#include <iostream>
#include "Map.h"
#include "Hero.h"

using namespace std;

int main()
{
	Hero some("papa", Warrior);
	Map level1("Level.txt");
	level1.setHero(some);
	level1.move();
	
	return 0;
}