#include <iostream>
#include <fstream>
#include <vector>

struct Range {
    int firstElement;
    int lastElement;
};

struct RangePair {
    Range firstRange;
    Range secondRange;
};

void getInput(std::vector<RangePair> &rangePairs) {

    std::ifstream ist(R"(F:\CLionProjects\AoC2022\Day 4\data.txt)");

    Range first{};
    Range second{};
    RangePair rangePair{};
    char dash, comma;

    while (ist >> first.firstElement && ist >> dash && ist >> first.lastElement
           && ist >> comma && ist >> second.firstElement && ist >> dash && ist >> second.lastElement) {
        rangePair.firstRange = first;
        rangePair.secondRange = second;
        rangePairs.push_back(rangePair);
    }
}

bool doesFullyContain(const RangePair rangePair) {
    return (rangePair.firstRange.firstElement <= rangePair.secondRange.firstElement
            && rangePair.firstRange.lastElement >= rangePair.secondRange.lastElement)
           || (rangePair.secondRange.firstElement <= rangePair.firstRange.firstElement
               && rangePair.secondRange.lastElement >= rangePair.firstRange.lastElement);
}

int main() {
    std::vector<RangePair> rangesPairs;
    getInput(rangesPairs);
    int counter = 0;
    for (const auto &rangePair: rangesPairs) {
        if (doesFullyContain(rangePair)) {
            counter++;
        }
    }
    std::cout << counter;

    return 0;
}
