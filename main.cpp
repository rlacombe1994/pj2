#include <iostream>
#include <string>
#include <vector>
#include "DefenseOfTheCodeGame.h"

using namespace std;

void printWinner(DefenseOfTheCodeGame game) 
{
		cout<<endl;
        if (game.isDraw())
                cout << "Tie!" << endl;
        else
                cout << game.getWinner() + " is victorious!" << endl;
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
 
int main()
{ 
    gameIntro();
    DefenseOfTheCodeGame game = DefenseOfTheCodeGame();
    game.run();
    printWinner(game);
    return 0;
}
