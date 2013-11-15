#include "MilitaryUnit.h"

using namespace std;

MilitaryUnit::MilitaryUnit(string name, int attackDamage) {
        this->name = name;
        this->attackDamage = attackDamage;
        armorDefense = 5;
        health = 100;
		type = "solo";
};

void MilitaryUnit::receiveDamage(int damage) 
{
        health -= (damage - armorDefense);
}

void MilitaryUnit::receiveHealth(int heal)
{
        health += heal;
}

string MilitaryUnit::getName() { return name; }

string MilitaryUnit::getType() { return type; }

int MilitaryUnit::getHealth() { return health; }
		
void MilitaryUnit::fight(MilitaryUnit *opponent) {
        opponent->receiveDamage(attackDamage);
};

bool MilitaryUnit::isAlive() {
        return this->health > 0;
}
