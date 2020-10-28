#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int result;

    cin >> result;

    bool isAwake = true;

    if (result == 0) {
        result++;
        cout << result << endl;
    }

    if (result > 0 && isAwake) {
        cout << "AWAKE" << endl;
    } else
        cout << "Is 23" << endl;

    switch (result) {
        case 1:
            cout << "Result is equal 1" << endl;
            break;
        case 10:
            cout << "Result is equal 10" << endl;
            break;
        default:
            cout << "Result is unknown" << endl;
    }
}