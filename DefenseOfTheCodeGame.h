#include <string>
#include "MilitaryUnit.h"

using namespace std;

class DefenseOfTheCodeGame{
        MilitaryUnit *unitA;
        MilitaryUnit *unitB;
		void addUnit(vector<MilitaryUnit*>& playersSquad, char classType, int numberOfUnits);
        void playRound();
public:
        DefenseOfTheCodeGame();
        void run();
        bool isGameOver();
        bool isDraw();
        string getWinner();
		vector<MilitaryUnit*> buildSquad();
};

