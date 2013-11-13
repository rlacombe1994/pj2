#include "MilitaryUnit.h"

BladeMaster::BladeMaster(string name,  int attackDamage) : MilitaryUnit(name, attackDamage)
{

}

void BladeMaster::fight(MilitaryUnit *opponent)
{
	opponent->receiveDamage(attackDamage);
	opponent->receiveDamage(attackDamage);
}
