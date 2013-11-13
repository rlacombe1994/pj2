#include "MilitaryUnit.h"

Necromancer::Necromancer(string name,  int attackDamage) : MilitaryUnit(name, attackDamage)
{

}

void Necromancer::lifesteal(int DamageDone)
{
	health += (DamageDone)/2;
}
void Necromancer::fight(MilitaryUnit *opponent)
{
	int damage =0;
	damage = opponent->getHealth();
	opponent->receiveDamage(attackDamage);
	damage -=  opponent->getHealth();
	lifesteal(damage);
}
