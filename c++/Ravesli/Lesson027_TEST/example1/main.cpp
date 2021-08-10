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

int main() {
    int number1 = readNumber();
    int number2 = readNumber();
    writeAnswer(number1 + number2);

    return 0;
}

