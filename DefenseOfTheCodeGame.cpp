#include "DefenseOfTheCodeGame.h"

using namespace std;

DefenseOfTheCodeGame::DefenseOfTheCodeGame()
{
	Computer.push_back(new Tank("Gordon",15));
	Computer.push_back(new Tank("Mr. Freeze",15));
	Computer.push_back(new Assassin("Bruce Wayne",15));
	Computer.push_back(new Assassin("Joker",15));
	Computer.push_back(new BladeMaster("Cat Woman",15));
	buildSquad(Player);
}

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
                int unitA = random(callPlayer());
                int unitB = random(callComputer());
                
		
		if(Player[unitA]->getType() == "splash")
			Player[unitA]->fight(Computer);
		else
			Player[unitA]->fight(Computer[unitB]);
	//	cout<< Player[unitA]->getName()<<": "<<Player[unitA]->getHealth()<<endl;
	
		if(Computer[unitA]->getType() == "splash")
			Computer[unitA]->fight(Player);
		else
			Computer[unitB]->fight(Player[unitA]);
	//	cout<< Player[unitB]->getName()<<": "<<Player[unitB]->getHealth()<<endl;
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
        return !isSquadAlive(callPlayer()) || !isSquadAlive(callComputer());
};

bool DefenseOfTheCodeGame::isDraw() 
{
        return !isSquadAlive(callPlayer()) && !isSquadAlive(callComputer());
}

string DefenseOfTheCodeGame::getWinner() {
        if (isSquadAlive(callPlayer())) return "The User";
        else return "The computer";
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
                                playersSquad.push_back(new Assassin(name,15));
                                break;
                        case 'B':
                                cout<<"what do you wish to name your BladeMaster?\t";
                                cin>>name;
                                playersSquad.push_back(new BladeMaster(name,15));
                                break;
						case 'b':
                                cout<<"what do you wish to name your Bomber?\t";
                                cin>>name;
                                playersSquad.push_back(new Bomber(name,15));
                                break;
                        case 'M':
                                cout<<"what do you wish to name your Monk?\t\t";
                                cin>>name;
                                playersSquad.push_back(new Monk(name,15));
                                break;
                        case 'N':
                                cout<<"what do you wish to name your Necromancer?\t";
                                cin>>name;
                                playersSquad.push_back(new Necromancer(name,15));
                                break;
						case 'P':
                                cout<<"what do you wish to name your Priest?\t";
                                cin>>name;
                                playersSquad.push_back(new Priest(name,15));
                                break;
                        case 'T':
                                cout<<"what do you wish to name your Tank?\t\t";
                                cin>>name;
                                playersSquad.push_back(new Tank(name,15));
                                break;        
                }
        }
        return;
 }

void DefenseOfTheCodeGame::buildSquad( vector<MilitaryUnit*>& playerSquad)
 {
        string Assassins    = "";
        string BladeMasters = "";
		string Bombers       = "";
        string Monks        = "";
        string Necromancers = "";
		string Priests       = "";
        string Tanks        = "";
        int totalUnits   = 0;
        while(totalUnits != 5)
        {
                cout<<"How many of each unit will you take to battle(maximum of 5)?"<<endl;
                cout<<"Assassins:";
                cin>>Assassins;
                cout<<"BladeMasters:";
                cin>>BladeMasters;
				cout<<"Bombers:";
                cin>>Bombers;
                cout<<"Monks:";
                cin>>Monks;
                cout<<"Necromancers:";
                cin>>Necromancers;
				cout<<"Priests:";
                cin>>Priests;
                cout<<"Tanks:";
                cin>>Tanks;
                
                totalUnits = atoi(Assassins.c_str()) + atoi(BladeMasters.c_str())+ atoi(Bombers.c_str()) + atoi(Monks.c_str()) + atoi(Necromancers.c_str())+ atoi(Priests.c_str())  + atoi(Tanks.c_str());
        }
        cout<<endl;
        addUnit(playerSquad,'A',atoi(Assassins.c_str()));
        addUnit(playerSquad,'B',atoi(BladeMasters.c_str()));
		addUnit(playerSquad,'b',atoi(Bombers.c_str()));
        addUnit(playerSquad,'M',atoi(Monks.c_str()));
        addUnit(playerSquad,'N',atoi(Necromancers.c_str()));
		addUnit(playerSquad,'P',atoi(Priests.c_str()));
        addUnit(playerSquad,'T',atoi(Tanks.c_str()));
 }
