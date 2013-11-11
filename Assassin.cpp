#include "MilitaryUnit.h"

bool Assassin::instaKill()
{
	int roll = rand()%100;
	if(roll<=5)
		return true;
	else
		return false;
}

void Assassin::fight(MilitaryUnit *opponent)
{
		if(instaKill())
			opponent->receiveDamage(opponent->health);
		else
			opponent->receiveDamage(attackDamage);	
}
