#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    for (int counter = 1; counter < 10; counter++) {
        if (counter % 3 == 0)
            continue;
        if (counter % 2 == 0)
            cout << " " << counter;
        if (counter % 10 == 0)
            break;
    }

    cout << endl;

    int i = 0;
    while (i < 20) {
        cout << " " << i;
        i++;
    }

    cout << endl;

    do {
        cout << " " << i;
        i++;
    } while (i < 40);
}