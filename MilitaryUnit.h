#include <string>

using namespace std;

class MilitaryUnit
{
	protected:
        string name;
        int attackDamage;
        int armorDefense;
        int health;

	public:
        MilitaryUnit(string name, int attackDamage);
        virtual void fight(MilitaryUnit *opponent);
        virtual void receiveDamage(int damage);
        string getName();
/*		int getHealth();
		int getAttack();
		int getArmor();
		void setHealth(int health); */
        bool isAlive();
};

class Necromancer : public MilitaryUnit
{
	public:
		void lifesteal(int attackDamage);
		void fight(MilitaryUnit *opponent);
};

class Tank : public MilitaryUnit
{
	public:
		int half_damage(int attackDamage);
		void receiveDamage(int damage); 
};

class Monk : public MilitaryUnit
{
		bool saved;
	public:
		Monk(string name,  int attackDamage);
		void save();
		void receiveDamage(int damage); 
};

class Assassin : public MilitaryUnit
{
	public:
		bool instaKill();
		void fight(MilitaryUnit *opponent);
};

class BladeMaster : public MilitaryUnit
{
	public:
		void fight(MilitaryUnit *opponent);
};
