#include "MilitaryUnit.h"

using namespace std;

MilitaryUnit::MilitaryUnit(string name, int attackDamage) {
        this->name = name;
        this->attackDamage = attackDamage;
        armorDefense = 5;
        health = 100;
};

void MilitaryUnit::receiveDamage(int damage) {
        health -= (damage - armorDefense);
}

string MilitaryUnit::getName() { return name; }

int MilitaryUnit::getHealth() { return health; }

int MilitaryUnit::getAttack(){ return attackDamage; }

int MilitaryUnit::getArmor() { return armorDefense; } 

void MilitaryUnit::setHealth(int health){ this->health = health;} 
		
void MilitaryUnit::fight(MilitaryUnit *opponent) {
        opponent->receiveDamage(attackDamage);
};

void MilitaryUnit::receiveHealth(int heal)
{
	health += heal;
}

bool MilitaryUnit::isAlive() {
        return this->health > 0;
}
