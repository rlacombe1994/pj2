#include "DefenseOfTheCodeGame.h"

using namespace std;

DefenseOfTheCodeGame::DefenseOfTheCodeGame() {
        unitA = new MilitaryUnit("Unit A", 15);
        unitB = new MilitaryUnit("Unit B", 20);
};

void DefenseOfTheCodeGame::run() {
        while (!isGameOver()) {
                playRound();
        }
};

void DefenseOfTheCodeGame::playRound() {
        unitA->fight(unitB);
        unitB->fight(unitA);
}

bool DefenseOfTheCodeGame::isGameOver() {
        return !unitA->isAlive() || !unitB->isAlive();
};

bool DefenseOfTheCodeGame::isDraw() {
        return !unitA->isAlive() && !unitB->isAlive();
}

string DefenseOfTheCodeGame::getWinner() {
        if (unitA->isAlive()) return unitA->getName();
        return unitB->getName();
}


void DefenseOfTheCodeGame::addUnit(vector<MilitaryUnit*>& playersSquad, char classType, int numberOfUnits)
 {
	string name;
	for(int i =0; i<numberOfUnits; ++i)
	{
		switch(classType)
		{
			case 'A':
				cout<<"what do you wish to name your Assassin?\t\t";
				cin>>name;
				playersSquad.push_back(new Assassin(name,10));
				break;
			case 'B':
				cout<<"what do you wish to name your BladeMaster?\t";
				cin>>name;
				playersSquad.push_back(new BladeMaster(name,10));
				break;
			case 'M':
				cout<<"what do you wish to name your Monk?\t\t";
				cin>>name;
				playersSquad.push_back(new Monk(name,10));
				break;
			case 'N':
				cout<<"what do you wish to name your Necromancer?\t";
				cin>>name;
				playersSquad.push_back(new Necromancer(name,10));
				break;
			case 'T':
				cout<<"what do you wish to name your Tank?\t\t";
				cin>>name;
				playersSquad.push_back(new Tank(name,10));
				break;	
		}
	}
	return;
 }
 
 vector<MilitaryUnit*> DefenseOfTheCodeGame::buildSquad()
 {
	vector<MilitaryUnit*> playersSquad;
	int Assassins =0;
	int BladeMasters =0;
	int Monks =0;
	int Necromancers =0;
	int Tanks =0;
	int totalUnits =0;
	while(totalUnits != 5)
	{
		cout<<"How many of each unit will you take to battle(maximum of 5)?"<<endl;
		cout<<"Assassins:";
		cin>>Assassins;
		cout<<"BladeMasters:";
		cin>>BladeMasters;
		cout<<"Monks:";
		cin>>Monks;
		cout<<"Necromancers:";
		cin>>Necromancers;
		cout<<"Tanks:";
		cin>>Tanks;
		
		totalUnits = Assassins + BladeMasters + Monks + Necromancers + Tanks;
	}
	cout<<endl;
	addUnit(playersSquad,'A',Assassins);
	addUnit(playersSquad,'B',BladeMasters);
	addUnit(playersSquad,'M',Monks);
	addUnit(playersSquad,'N',Necromancers);
	addUnit(playersSquad,'T',Tanks);
	
	return playersSquad;
 }
