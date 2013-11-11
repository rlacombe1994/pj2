#include "MilitaryUnit.h"

int Tank::half_damage(int attackDamage)
{
	return (attackDamage/2);
}

void Tank::receiveDamage(int damage)
{
	int trueDamage = half_damage(damage);
	health -= trueDamage - armorDefense;
}
