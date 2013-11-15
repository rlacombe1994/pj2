#include "MilitaryUnit.h"

Assassin::Assassin(string name,  int attackDamage) : MilitaryUnit(name, attackDamage)
{

}

bool Assassin::instaKill()
{
	int roll = rand()%101;
	if(roll<=5)
		return true;
	else
		return false;
}

void Assassin::fight(MilitaryUnit *opponent)
{
		if(instaKill())
		{
			opponent->receiveDamage(2*(opponent->getHealth()));
			cout<<name<<" has blown a fatal death strike!"<<endl;
		}
		else
			opponent->receiveDamage(attackDamage);	
}
