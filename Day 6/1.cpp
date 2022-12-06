#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>


void getInput(std::string &dataStream) {
    std::ifstream ist(R"(F:\CLionProjects\AoC2022\Day 6\data.txt)");
    while (ist >> dataStream);
}

bool areFourCharTheSame() {
    const int size = 4;


}

int main() {
    std::string dataStream;
    getInput(dataStream);

    auto it = dataStream.begin();
    for (int i = 0; i < dataStream.length(); i++) {
        std::string fragment = dataStream.substr(i, 4);
        it = std::unique(fragment.begin(), fragment.end());
        if(fragment.end() == it){
            std::cout <<  i;
            break;
        }
    }
}


