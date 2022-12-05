#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>

void getInput(std::vector<char> &badges){
    std::ifstream ist(R"(F:\CLionProjects\AoC2022\Day 3\data.txt)");

    std::string firstLine;
    std::string secondLine;
    std::string thirdLine;

    std::set<char> firstSet;
    std::set<char> secondSet;
    std::set<char> thirdSet;
    std::vector<char> tmp;

    while(ist >> firstLine && ist >> secondLine && ist >> thirdLine) {
        for (const char c: firstLine) {
            firstSet.insert(c);
        }
        for (const char c: secondLine) {
            secondSet.insert(c);
        }
        for (const char c: thirdLine) {
            thirdSet.insert(c);
        }
        std::set_intersection(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(), std::back_inserter(tmp));
        std::sort(tmp.begin(), tmp.end());
        std::set_intersection(thirdSet.begin(), thirdSet.end(), tmp.begin(), tmp.end(),
                              std::back_inserter(badges));

        firstSet.clear();
        secondSet.clear();
        thirdSet.clear();
        tmp.clear();
    }
}

void printInput(const std::vector<char> &badges) {
    for (const char ch: badges) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

int countPoints(const std::vector<char> &badges) {

    int sum = 0;

    for (const char c: badges) {
        if (std::islower(c)) {
            sum += c - 96;
        } else {
            sum += c - 38;
        }
    }
    return sum;
}

int main(){
    std::vector<char> badges;
    getInput(badges);
    printInput(badges);
    std::cout << countPoints(badges);
}
