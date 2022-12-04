#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

struct DuelPair {
    char opponent;
    char me;
};

void getInput(std::vector<char> &opponentMoves, std::vector<char> &order) {
    std::ifstream is(R"(F:\CLionProjects\AoC2022\Day 2\data.txt)");

    char opponentMove, ord;

    while (is >> opponentMove && is >> ord) {
        opponentMoves.push_back(opponentMove);
        order.push_back(ord);
    }
}

int pointsForDuel(const char opponent, const char me) {
    std::vector<DuelPair> losingCombinations = {{'A', 'Z'},
                                                {'B', 'X'},
                                                {'C', 'Y'}};

    std::vector<DuelPair> winningCombinations = {{'A', 'Y'},
                                                 {'B', 'Z'},
                                                 {'C', 'X'}};

    for (const auto &combination: winningCombinations) {
        if (opponent == combination.opponent && me == combination.me) {
            return 6;
        }
    }

    for (const auto &combination: losingCombinations) {
        if (opponent == combination.opponent && me == combination.me) {
            return 0;
        }
    }
    return 3;
}

int shapeSum(const char c) {
    if (c == 'X') {
        return 1;
    }
    if (c == 'Y') {
        return 2;
    }
    if (c == 'Z') {
        return 3;
    }
    return 0;
}

char myMove(const char opponent, const char order) {
    std::vector<DuelPair> losingCombinations = {{'A', 'Z'},
                                                {'B', 'X'},
                                                {'C', 'Y'}};

    std::vector<DuelPair> winningCombinations = {{'A', 'Y'}, // rock paper
                                                 {'B', 'Z'}, // paper scissors
                                                 {'C', 'X'}}; // scissors rock

    std::vector<DuelPair> drawCombinations = {{'A', 'X'},
                                              {'B', 'Y'},
                                              {'C', 'Z'}};


    if (order == 'Z') {
        for (const auto &combination: winningCombinations) {
            if (opponent == combination.opponent) {
                return combination.me;
            }
        }
    }

    if (order == 'X') {
        for (const auto &combination: losingCombinations) {
            if (opponent == combination.opponent) {
                return combination.me;
            }
        }
    }

    if (order == 'Y') {
        for (const auto &combination: drawCombinations) {
            if (opponent == combination.opponent) {
                return combination.me;
            }
        }
    }
    return 0;
}

int main() {

    std::vector<char> opponentMoves;
    std::vector<char> orders;
    std::vector<char> myMoves;

    getInput(opponentMoves, orders);

    int totalSum = 0;

    for (int i = 0; i < orders.size(); i++) {
        myMoves.push_back(myMove(opponentMoves[i], orders[i]));
        totalSum += pointsForDuel(opponentMoves[i], myMoves[i]);
        totalSum += shapeSum(myMoves[i]);
    }
    std::cout << totalSum;
}