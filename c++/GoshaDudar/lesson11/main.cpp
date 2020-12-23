#include <iostream>
#include <clocale>

using namespace std;

int main(int argc, const char * argv[]) {
    setlocale(LC_CTYPE, "Russian");

    char string[500];
    std::cout << "Введите строку: " << endl;
    std::cin >> string;
    std::cout << string << endl;

    return 0;
}
