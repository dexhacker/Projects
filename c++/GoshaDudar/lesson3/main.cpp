#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int num_1, num_2, result;

    cin >> num_1;
    cin >> num_2;
    result = num_1 + num_2;
    cout << num_1 << " + " << num_2 << " = " << result << endl;

    result -= 4;
    result++;
    cout << result << endl;

    return 0;
}
