#include "MilitaryUnit.h"

Priest::Priest(string name,  int attackDamage) : MilitaryUnit(name, attackDamage)
{
        type="splashheal";
}

void Priest::fightAll(vector<MilitaryUnit*>& targets)
{        
        int Alive=0;
        
        for(int i=0;i<targets.size();++i)
        {
                if(targets[i]->isAlive()==true) ++Alive;
        }

        int heal=(attackDamage/Alive);
        
        for(int i=0;i<targets.size();++i)
        {
                if(targets[i]->isAlive()==true) 
				{
					targets[i]->receiveHealth(heal);
					cout << name << " has healed " << targets[i]->getName() << " for " << heal << endl;
				}
        }
}
