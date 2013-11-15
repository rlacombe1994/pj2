#include <iostream>
#include <string>
#include <vector>
#include "DefenseOfTheCodeGame.h"

using namespace std;

void printWinner(DefenseOfTheCodeGame game) {
        if (game.isDraw())
                cout << "Tie!" << endl;
        else
                cout << game.getWinner() + " is the victor!" << endl;
}

 void classSummary()
 {
	cout<<"This game include 5 basic unit classes."<<endl<<endl;
	cout<<"Assassin:\t has a small chance to instantly kill his opponent."<<endl;
	cout<<"Blade Master:\t wields two blades allowing for a double strike."<<endl;
	cout<<"Monk:\t\t has a save ability that is triggered upon his/her first death."<<endl;
	cout<<"Necromancer:\t half of the damage dealt by this unit is added to its health."<<endl;
	cout<<"Tank:\t\t receives half damage from all incoming damage sources."<<endl<<endl;
 }

void basicRules()
{
	cout<<"This game will determine whether or not you have what it takes to best the \tcomputer ";
	cout<<"in a 5v5 battle."<<endl;
	cout<<"Your 5 man squad can be made of any combination of units, Choose wisely"<<endl<<endl;
}
 
void gameIntro()
 {
	classSummary();
	basicRules();
 }
 
 void addUnit(vector<MilitaryUnit*>& playersSquad, char classType, int numberOfUnits)
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
 
 vector<MilitaryUnit*> buildSquad()
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
 
int main()
 {
	gameIntro();
    DefenseOfTheCodeGame game = DefenseOfTheCodeGame();
	buildSquad();
	
	/*
    game.run();

    printWinner(game);
	*/
    return 0;
}
