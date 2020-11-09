#include <iostream>
#include <clocale>

using namespace std;

int main(int argc, const char * argv[]) {
    setlocale(LC_CTYPE, "Russian");

    char string[500];
    cout << "Введите строку: " << endl;
    gets(string);
    cout << string << endl;

    return 0;
}
