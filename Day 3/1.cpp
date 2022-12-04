#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>


void getInput(std::vector<char> &sharedItems) {
    std::ifstream ist(R"(F:\CLionProjects\AoC2022\Day 3\data.txt)");

    std::set<char> firstHalf;
    std::set<char> secondHalf;

    std::string line;

    while (std::getline(ist, line)) {
        std::string firstHalfLine = line.substr(0, line.size() / 2);
        std::string secondHalfLine = line.substr(line.size() / 2);

        for (const char c: firstHalfLine) {
            firstHalf.insert(c);
        }

        for (const char c: secondHalfLine) {
            secondHalf.insert(c);
        }

        std::set_intersection(firstHalf.begin(), firstHalf.end(), secondHalf.begin(), secondHalf.end(),
                              std::back_inserter(sharedItems));
        firstHalf.clear();
        secondHalf.clear();
    }
}

void printInput(const std::vector<char> &sharedItems) {
    for (const char ch: sharedItems) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

int countPoints(const std::vector<char> &sharedItems) {

    int sum = 0;

    for (const char c: sharedItems) {
        if (std::islower(c)) {
            sum += c - 96;
        } else {
            sum += c - 38;
        }
    }
    return sum;
}

int main() {
    std::vector<char> sharedItems;
    getInput(sharedItems);
    printInput(sharedItems);

    std::cout << countPoints(sharedItems);
}