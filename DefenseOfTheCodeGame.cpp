#include "DefenseOfTheCodeGame.h"

using namespace std;

void DefenseOfTheCodeGame::run() {
        while (!isGameOver()) 
		{
                playRound();
        }
};

int DefenseOfTheCodeGame::random(vector<MilitaryUnit*> squad)
{
	int unitA = rand()%5;
	while(true)
	{
		if(squad[unitA]->isAlive()==true) return unitA;
		else unitA = rand()%5;
	}
} 

void DefenseOfTheCodeGame::playRound() 
{
		int unitA = random(callSquadA());
		int unitB = random(callSquadB());
		
        squadA[unitA]->fight(squadB[unitB]);
        squadB[unitB]->fight(squadA[unitA]);
}

bool DefenseOfTheCodeGame::isSquadAlive(vector<MilitaryUnit*> squad)
{
	for(int i=0;i<squad.size();++i)
	{
		if(squad[i]->isAlive()==true) return true;
	}
	return false;
}

bool DefenseOfTheCodeGame::isGameOver() 
{
        return !isSquadAlive(callSquadA()) || !isSquadAlive(callSquadB());
};

bool DefenseOfTheCodeGame::isDraw() 
{
        return !isSquadAlive(callSquadA()) && !isSquadAlive(callSquadB());
}

string DefenseOfTheCodeGame::getWinner() {
        if (isSquadAlive(callSquadA())) return "Squad A";
        else return "Squad B";
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
