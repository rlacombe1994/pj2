#include "MilitaryUnit.h"

Monk::Monk(string name,  int attackDamage) : MilitaryUnit(name, attackDamage)
{
	saved = false;
}

void Monk::save()
{
	health =1;
	saved = true;
	cout<<name<<" was saved due to the monk's divine protection!"<<endl; 
}

void Monk::receiveDamage(int damage) 
{
	health -= damage - armorDefense;
	if(health <= 0 && saved == false)
		save();
}
