#include "MilitaryUnit.h"

using namespace std;

class DefenseOfTheCodeGame{
       	vector<MilitaryUnit*> squadA;
       	vector<MilitaryUnit*> squadB;
	void addUnit(vector<MilitaryUnit*>& playersSquad, char classType, int numberOfUnits);
        void playRound();
public:
        DefenseOfTheCodeGame();
        
	vector<MilitaryUnit*> buildSquad();
	vector<MilitaryUnit*> callSquadA() {return squadA;}
	vector<MilitaryUnit*> callSquadB() {return squadB;}
		
	bool isGameOver();
        bool isDraw();
	bool isSquadAlive(vector<MilitaryUnit*> squad);
		
	int random(vector<MilitaryUnit*> squad);
		
	string getWinner();
		
        void run(); 
};

