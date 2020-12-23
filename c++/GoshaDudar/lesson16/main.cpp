#include <iostream>

using namespace std;

float perimeter(float x, float y, float z);
float perimeter(float x, float y, float z, float d);

int main() {
    cout << perimeter(12.3, 45.6, 78.9) << endl;
    cout << perimeter(12.3, 45.6, 78.9, 22.2) << endl;

    return 0;
}

float perimeter(float x, float y, float z) {
    return x + y + z;
}

float perimeter(float x, float y, float z, float d) {
    return x + y + z + d;
}
