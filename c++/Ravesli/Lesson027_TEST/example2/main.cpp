#include "io.h"

int main() {
    int number1 = readNumber();
    int number2 = readNumber();
    writeAnswer(number1 + number2);

    return 0;
}

