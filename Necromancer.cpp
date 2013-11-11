#include "MilitaryUnit.h"

void Necromancer::lifesteal(int DamageDone)
{
	health += (DamageDone)/2;
}
void Necromancer::fight(MilitaryUnit *opponent)
{
	int damage =0;
	damage = opponent->health;
	opponent->receiveDamage(attackDamage);
	damage -=  opponent->health;
	lifesteal(damage);
}
