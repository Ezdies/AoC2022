#include <iostream>
#include <fstream>
#include <unordered_set>

void getInput(std::string &dataStream) {
    std::ifstream ist(R"(F:\CLionProjects\AoC2022\Day 6\data.txt)");
    while (ist >> dataStream);
}

int result(const std::string &dataStream){
    const int requiredSize = 14;
    std::unordered_set<char> uniqueChars;

    for (int i = 0; i < dataStream.length(); i++) {
        std::string fragment = dataStream.substr(i, requiredSize);

        for (const char c: fragment) {
            uniqueChars.insert(c);
        }
        if (uniqueChars.size() == requiredSize) {
            return i + requiredSize;
        }
        uniqueChars.clear();
    }
    return 0;
}

int main() {
    std::string dataStream;
    getInput(dataStream);
    std::cout << result(dataStream);
}


