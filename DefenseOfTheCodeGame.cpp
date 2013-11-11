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
