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
    std::vector<char> vector1{'Z', 'N'};
    std::vector<char> vector2{'M', 'C', 'D'};
    std::vector<char> vector3{'P'};

    std::vector<std::vector<char>> vectorOfVectors{vector1, vector2, vector3};

    for (int i = 0; i < vectorOfStacks.size(); i++) {
        for (const char c: vectorOfVectors[i]) {
            vectorOfStacks[i].push(c);
        }
    }
}



void moveStacks(std::vector<std::stack<char>> &vectorOfStacks, const std::vector<Order>& vectorOfOrders){
//    std::vector<char> tmpStack;
//
//    for(int i = 0; i < vectorOfOrders.size(); i++){
//        for(int j = 0; j < vectorOfStacks[vectorOfOrders[i].startingStack - 1].size(); j++){
//            for(int k = 0; k < vectorOfOrders[i].quantity; k++){
//                tmpStack.push_back(vectorOfStacks[vectorOfOrders[i].startingStack - 1].top());
//            }
//        }
//        vectorOfStacks[vectorOfOrders[i].startingStack - 1].pop();
//
//    }
//    for(const auto c : tmpStack){
//        std::cout << c << std::endl;
//    }
//    std::cout << vectorOfStacks[vectorOfOrders[0].startingStack - 1].top();
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

void printOrders(const std::vector<Order> &vectorOfOrders) {
    for (const auto &ord: vectorOfOrders) {
        std::cout << ord.quantity << " " << ord.startingStack << " " << ord.destinationStack << std::endl;
    }
    std::cout << std::endl;
}

void takeQuantityFromStack(std::stack<char> &s, const int quantity){
    std::vector<char> tmpElements;
    for(int i = 0; i <  quantity; i++){
        tmpElements.push_back(s.top());
        s.pop();
    }
}

int main() {

    std::stack<char> stack1;
    std::stack<char> stack2;
    std::stack<char> stack3;

    std::vector<std::stack<char>> vectorOfStacks{stack1, stack2, stack3};

    std::vector<Order> vectorOfOrders;

    getInput(vectorOfOrders);
    initializeStacks(vectorOfStacks);
    printStacks(vectorOfStacks);
    printOrders(vectorOfOrders);
    takeQuantityFromStack(stack2, 1);
}
