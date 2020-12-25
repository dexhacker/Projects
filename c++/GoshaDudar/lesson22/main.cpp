#include <iostream>

using namespace std;

class Test {
private:
    int a, b, c;

public:
    void set(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void get() {
        cout << "A = " << a << ", B = " << b << ", C = " << c << endl;
    }
};

int main() {
    Test test;
    test.set(12, 23, 1);
    test.get();

    return 0;
}