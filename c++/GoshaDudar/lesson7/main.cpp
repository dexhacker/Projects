#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int number1, number2;
    cout << "Enter 2 numbers:" << endl;
    cin >> number1;
    cin >> number2;

    try {
        if (number2 == 0)
            throw 123;
        cout << number1 << " / " << number2 << " = " << number1 / number2 << endl;
    } catch (int i) {
        cout << "Error(" << i << "): Divide by zero" << endl;
    }
}