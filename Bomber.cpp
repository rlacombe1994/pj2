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

void Bomber::fight(vector<MilitaryUnit*>& opponents)
{
	int alive = SquadRemaining( opponents );
	int damagePerUnit = attackDamage/alive;
	int extraDamage = attackDamage%alive;
	int firstUnitIndex =0;
	
	for(int i =0; i<opponents.size();++i)
		if(opponents[i]->isAlive())
		{
			opponents[i]->receiveDamage(damagePerUnit + extraDamage );
			firstUnitIndex =1;
			break;
		}
	
	for(int i =0; i<opponents.size();++i)
		if(opponents[i]->isAlive() && i != firstUnitIndex )
			opponents[i]->receiveDamage(damagePerUnit);
}
