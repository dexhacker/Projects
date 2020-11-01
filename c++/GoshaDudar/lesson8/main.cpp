#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int arr[] = {3, 7, 5};
    cout << arr[0] << endl;

    arr[2] = 34;

    for (int i = 0; i < 3; i++)
        cout << arr[i] << " ";

    cout << endl;
    cout << endl;

    int newArr[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cout << newArr[i][j] << " ";
        cout << endl;
    }

    return 0;
}
