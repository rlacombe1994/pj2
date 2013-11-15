#include <string>
#include <iostream>
#include <vector>

using namespace std;

class MilitaryUnit
{
	protected:
        string name;
        int attackDamage;
        int armorDefense;
        int health;
        string type;

	public:
        MilitaryUnit(string name, int attackDamage);
        virtual void fight(MilitaryUnit *opponent);
        virtual void receiveDamage(int damage);
        void receiveHealth(int heal);
        string getName();
        string getType();
	int getHealth();
	int getAttack();
	int getArmor();
	void setHealth(int health); 
        bool isAlive();
};

class Necromancer : public MilitaryUnit
{
	public:
		Necromancer(string name,  int attackDamage);
		void lifesteal(int attackDamage);
		void fight(MilitaryUnit *opponent);
};

class Tank : public MilitaryUnit
{
	public:
		Tank(string name,  int attackDamage);
		int half_damage(int attackDamage);
		void receiveDamage(int damage); 
};

class Monk : public MilitaryUnit
{
	protected:
		bool saved;
	public:
		Monk(string name,  int attackDamage);
		void save();
		void receiveDamage(int damage); 
};

class Assassin : public MilitaryUnit
{
	public:
		Assassin(string name,  int attackDamage);
		bool instaKill();
		void fight(MilitaryUnit *opponent);
};

class BladeMaster : public MilitaryUnit
{
	public:
		BladeMaster(string name,  int attackDamage);
		void fight(MilitaryUnit *opponent);
};

class Priest : public MilitaryUnit
{
	public:
		Priest(string name,  int attackDamage);
		void fightAll(vector<MilitaryUnit*>& Allies);
};


class Bomber : public MilitaryUnit
{
   	public:
     		Bomber(string name,  int attackDamage);
     		void fightAll(vector<MilitaryUnit*>& opponents);
}; 
