#include "MilitaryUnit.h"

using namespace std;

class DefenseOfTheCodeGame{
        vector<MilitaryUnit*> Computer;
        vector<MilitaryUnit*> Player;
        void addUnit(vector<MilitaryUnit*>& playersSquad, char classType, int numberOfUnits);
        void playRound();
public:
        DefenseOfTheCodeGame();
        
        void buildSquad(vector<MilitaryUnit*>& PlayerSquad);
        vector<MilitaryUnit*> callPlayer() {return Player;}
        vector<MilitaryUnit*> callComputer() {return Computer;}
                
        bool isGameOver();
        bool isDraw();
        bool isSquadAlive(vector<MilitaryUnit*> squad);
                
        int random(vector<MilitaryUnit*> squad);
                
        string getWinner();
                
        void run(); 
};
