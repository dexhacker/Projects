#include <iostream>
#include <cmath>

using namespace std;

void printValue();

int value = 15;

int main() {
    cout << value << endl;
    int value= 10;
    cout << value << endl;
    printValue();

    cout << "Pow - " << pow(2, 4) << endl;
    cout << "Abs - " << abs(-23) << endl;
    cout << "Sin - " << sin(10) << endl;
    cout << "Cos - " << cos(10) << endl;
    cout << "Sqrt - " << sqrt(16) << endl;
    cout << "Ceil - " << ceil(23.67) << endl;
    cout << "Floor - " << floor(23.67) << endl;
    cout << "Exp - " << exp(2) << endl;
    cout << "Log - " << log(4) << endl;
    cout << "Log10 - " << log10(100) << endl;

    return 0;
}

void printValue() {
    cout << value << endl << endl;
}