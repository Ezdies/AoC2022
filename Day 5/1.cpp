#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

struct Order {
    int quantity;
    int startingStack;
    int destinationStack;
};

void getInput(std::vector<Order> &vectorOfOrders) {
    std::ifstream ist(R"(F:\CLionProjects\AoC2022\Day 5\data.txt)");

    Order order{};
    std::string tmp;

    while (ist >> tmp && ist >> order.quantity && ist >> tmp && ist >> order.startingStack && ist >> tmp &&
           ist >> order.destinationStack) {
        vectorOfOrders.push_back(order);
    }
}

void initializeStacks(std::vector<std::stack<char>> &vectorOfStacks) {
    std::vector<char> vector1{'G', 'T', 'R', 'W'};
    std::vector<char> vector2{'G', 'C', 'H', 'P', 'M', 'S', 'V', 'W'};
    std::vector<char> vector3{'C', 'L', 'T', 'S', 'G', 'M'};
    std::vector<char> vector4{'J', 'H', 'D', 'M', 'W', 'R', 'F'};
    std::vector<char> vector5{'P', 'Q', 'L', 'H', 'S', 'W', 'F', 'J'};
    std::vector<char> vector6{'P', 'J', 'D', 'N', 'F', 'M', 'S'};
    std::vector<char> vector7{'Z', 'B', 'D', 'F', 'G', 'C', 'S', 'J'};
    std::vector<char> vector8{'R', 'T', 'B'};
    std::vector<char> vector9{'H', 'N', 'W', 'L', 'C'};


    std::vector<std::vector<char>> vectorOfVectors{vector1, vector2, vector3, vector4, vector5, vector6, vector7,
                                                   vector8, vector9};

    for (int i = 0; i < vectorOfStacks.size(); i++) {
        for (const char c: vectorOfVectors[i]) {
            vectorOfStacks[i].push(c);
        }
    }
}

void takeQuantityFromStack(const int quantity, std::stack<char> &startingStack, std::vector<char> &takenElements) {
    for (int i = 0; i < quantity; i++) {
        takenElements.push_back(startingStack.top());
        startingStack.pop();
    }
}

void putQuantityOnStack(std::stack<char> &destinationStack, std::vector<char> &takenElements) {
    for (const char c: takenElements) {
        destinationStack.push(c);
    }
    takenElements.clear();
}

void moveStacks(std::vector<std::stack<char>> &vectorOfStacks, const std::vector<Order> &vectorOfOrders,
                std::vector<char> &tmpElements) {
    for (const auto order: vectorOfOrders) {
        takeQuantityFromStack(order.quantity, vectorOfStacks[order.startingStack - 1],
                              tmpElements);
        putQuantityOnStack(vectorOfStacks[order.destinationStack - 1], tmpElements);
    }
}

void printStacks(const std::vector<std::stack<char>> &vectorOfStacks) {
    for (auto s: vectorOfStacks) {
        while (!s.empty()) {
            std::cout << s.top() << std::endl;
            s.pop();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printStackTops(const std::vector<std::stack<char>> &vectorOfStacks){
    for(const auto &s : vectorOfStacks){
        std::cout << s.top();
    }
}

void printOrders(const std::vector<Order> &vectorOfOrders) {
    for (const auto &ord: vectorOfOrders) {
        std::cout << ord.quantity << " " << ord.startingStack << " " << ord.destinationStack << std::endl;
    }
    std::cout << std::endl;
}

void printTmpStack(const std::vector<char> &tmpStack) {
    for (const char c: tmpStack) {
        std::cout << c << std::endl;
    }
}

int main() {

    std::stack<char> stack1;
    std::stack<char> stack2;
    std::stack<char> stack3;
    std::stack<char> stack4;
    std::stack<char> stack5;
    std::stack<char> stack6;
    std::stack<char> stack7;
    std::stack<char> stack8;
    std::stack<char> stack9;
    std::vector<char> takenElements;

    std::vector<std::stack<char>> vectorOfStacks{stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8,
                                                 stack9};

    std::vector<Order> vectorOfOrders;

    getInput(vectorOfOrders);
    initializeStacks(vectorOfStacks);
    printStacks(vectorOfStacks);
    printOrders(vectorOfOrders);
    moveStacks(vectorOfStacks, vectorOfOrders, takenElements);
    printTmpStack(takenElements);
    printStacks(vectorOfStacks);
    printStackTops(vectorOfStacks);
}
