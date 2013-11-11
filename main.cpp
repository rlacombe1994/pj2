#include <iostream>
#include <string>
#include "DefenseOfTheCodeGame.h"

using namespace std;

void printWinner(DefenseOfTheCodeGame game) {
        if (game.isDraw())
                cout << "Tie!" << endl;
        else
                cout << game.getWinner() + " is the victor!" << endl;
}

int main() {
        DefenseOfTheCodeGame game = DefenseOfTheCodeGame();

        game.run();

        printWinner(game);

        char anyKey;
        cin >> anyKey;

        return 0;
}
