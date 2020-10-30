#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "1-random number = " << 1 + rand() % 80 << endl;
    cout << "2-random number = " << 1 + rand() % 80 << endl;
    cout << "3-random number = " << 1 + rand() % 80 << endl;
    cout << "4-random number = " << 1 + rand() % 80 << endl;
    cout << "5-random number = " << 1 + rand() % 80 << endl;
    cout << "6-random number = " << 1 + rand() % 80 << endl;
    cout << "7-random number = " << 1 + rand() % 80 << endl;
    cout << "8-random number = " << 1 + rand() % 80 << endl;

    string name, name1;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your name1: ";
    getline(cin, name1);
    if (name == name1)
        cout << "Equal" << endl;
    else
        cout << "Error" << endl;

    cout << name << " " << name1 << endl;

    return 0;
}