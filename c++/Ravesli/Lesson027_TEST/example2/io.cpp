#include <iostream>

int readNumber() {
    std::cout << "Enter number: ";
    int value;
    std::cin >> value;
    return value;
}

void writeAnswer(int answer) {
    std::cout << "Your answer: " << answer << std::endl;
}

