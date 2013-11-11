#include <string>
#include "MilitaryUnit.h"

using namespace std;

class DefenseOfTheCodeGame{
        MilitaryUnit *unitA;
        MilitaryUnit *unitB;
        void playRound();
public:
        DefenseOfTheCodeGame();
        void run();
        bool isGameOver();
        bool isDraw();
        string getWinner();
};
