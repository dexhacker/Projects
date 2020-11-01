#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    const float pi = 3.14;

    cout << pi << endl << endl;

    int value = 8;
    int *ptrValue = &value;

    cout << *ptrValue << endl;

    cout << &value << " - " << ptrValue << endl << endl;

    int number = 10;
    int &ref = number;

    cout << &ref << " - " << number << endl;
    cout << ref << " - " << number << endl;

    cout << i << endl;

    return 0;
}
