#include "MilitaryUnit.h"

Priest::Priest(string name,  int attackDamage) : MilitaryUnit(name, attackDamage)
{
	type="Splash";
}

void Priest::fight(vector<MilitaryUnit*>& Allies)
{	
	int Alive=0;
	
	for(int i=0;i<Allies.size();++i)
	{
		if(Allies[i]->isAlive()==true) ++Alive;
	}

	int heal=(attackDamage/Alive);
	
	for(int i=0;i<Allies.size();++i)
	{
		if(Allies[i]->isAlive()==true) Allies[i]->receiveHealth(heal);
	}
}
