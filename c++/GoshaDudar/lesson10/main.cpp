#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int *ptrNum = new int(7);
    *ptrNum = 5;

    cout << *ptrNum << endl;

    delete ptrNum;

    float *ptrArray = new float[10];

    for (int i = 0; i < 10; i++)
        ptrArray[i] = rand() % 80 + 1;

    for (int i = 0; i < 10; i++)
        cout << ptrArray[i] << " ";

    delete [] ptrArray;

    return 0;
}
