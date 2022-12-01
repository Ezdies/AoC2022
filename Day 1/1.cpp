#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream ifstream(R"(F:\CLionProjects\AoC2022\Day 1\data.txt)");

    int sum = 0;
    int maxi = 0;

    std::string line;
    while (std::getline(ifstream, line)) {
        if (!line.empty()) {
            sum += std::stoi(line);
        } else {
            maxi = std::max(maxi, sum);
            sum = 0;
        }
    }

    std::cout << maxi;

    return 0;
}

