#include "MilitaryUnit.h"

Monk::Monk(string name,  int attackDamage)
{
	this->name = name;
    this->attackDamage = attackDamage;
    armorDefense = 5;
    health = 100;
	saved = false;
}

void Monk::save()
{
	health =1;
	saved = true;
}

void Monk::receiveDamage(int damage);
{
	health -= damage - armorDefense;
	if(health <= 0 && saved == false)
		save();
}
