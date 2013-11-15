#include "MilitaryUnit.h"

Bomber::Bomber(string name,  int attackDamage) : MilitaryUnit(name, attackDamage)
{
	type = "splash";
}

int SquadRemaining(vector<MilitaryUnit*>& Squad)
{
	int alive =0;
	for(int i =0; i<Squad.size();++i)
		if(Squad[i]->isAlive())
			++alive;
	
	return alive;
}

void Bomber::fightAll(vector<MilitaryUnit*>& targets)
{
	int alive = SquadRemaining( targets );
	int damagePerUnit = attackDamage/alive;
	int extraDamage = attackDamage%alive;
	int firstUnitIndex =0;
	
	for(int i =0; i<targets.size();++i)
		if(targets[i]->isAlive())
		{
			targets[i]->receiveDamage(damagePerUnit + extraDamage );
			firstUnitIndex =1;
			break;
		}
	
	for(int i =0; i<targets.size();++i)
		if(targets[i]->isAlive() && i != firstUnitIndex )
			targets[i]->receiveDamage(damagePerUnit);
}
