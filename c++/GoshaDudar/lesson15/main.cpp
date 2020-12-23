#include <iostream>

using namespace std;

void funct(int num);
float sum(float x, float y);

int main(int argc, const char * argv[]) {
    funct(234);
    cout << sum(12.34, 56.78);

    return 0;
}

void funct(int num) {
    cout << "Parameter - " << num << endl;
}

float sum(float x, float y) {
    return x + y;
}
