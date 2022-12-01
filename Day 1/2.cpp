#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

int main() {

    std::ifstream ifstream(R"(F:\CLionProjects\AoC2022\Day 1\data.txt)");
    int sum = 0;
    std::vector<int> calories;

    std::string line;
    while (std::getline(ifstream, line)) {
        if (!line.empty()) {
            sum += std::stoi(line);
            calories.push_back(sum);
        } else {
            sum = 0;
        }
    }

    std::sort(calories.begin(), calories.end(), std::greater<>());
    std::cout << std::accumulate(calories.begin(), calories.begin() + 3, 0);

    return 0;
}