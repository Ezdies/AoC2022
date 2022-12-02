#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>


void getInput(std::vector<char>&opponentMoves, std::vector<char>&myMoves){
    std::ifstream is(R"(F:\CLionProjects\AoC2022\Day 2\data.txt)");

    char opponentMove, myMove;

    while (is >> opponentMove && is >> myMove) {
        opponentMoves.push_back(opponentMove);
        myMoves.push_back(myMove);
    }
}

//int opponentShapeSum(const std::vector<char> &opponentMoves) {
//    return std::accumulate(opponentMoves.begin(), opponentMoves.end(), 0, [](int res, const char c) {
//        if (c == 'A') {
//            res += 1;
//        }
//        if (c == 'B') {
//            res += 2;
//        }
//        if (c == 'C') {
//            res += 3;
//        }
//        return res;
//    });
//}

int pointsForDuel(const char opponent, const char me) {
    std::vector<std::pair<char, char>> losingCombinations = {std::make_pair('A', 'Z'), std::make_pair('B', 'X'),
                                                             std::make_pair('C', 'Y')};

    std::vector<std::pair<char, char>> winningCombinations = {std::make_pair('A', 'Y'), std::make_pair('B', 'Z'),
                                                              std::make_pair('C', 'X')};


    for (const auto &combination: winningCombinations) {
        if (opponent == combination.first && me == combination.second) {
            return 6;
        }
    }

    for (const auto &combination: losingCombinations) {
        if (opponent == combination.first && me == combination.second) {
            return 0;
        }
    }
    return 3;
}

int shapeSum(const char c){
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

//int myShapeSum(const std::vector<char> &myMoves) {
//    return std::accumulate(myMoves.begin(), myMoves.end(), 0, [](int res, const char c) {
//        if (c == 'X') {
//            res += 1;
//        }
//        if (c == 'Y') {
//            res += 2;
//        }
//        if (c == 'Z') {
//            res += 3;
//        }
//        return res;
//    });
//}

int main() {

    std::vector<char> opponentMoves;
    std::vector<char> myMoves;

    getInput(opponentMoves, myMoves);

    int totalSum = 0;

    for(int i = 0; i < myMoves.size(); i++){
        totalSum += pointsForDuel(opponentMoves[i], myMoves[i]);
        totalSum += shapeSum(myMoves[i]);
    }

    std::cout << totalSum;
}

