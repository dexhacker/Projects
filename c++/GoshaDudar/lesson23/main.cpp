#include <iostream>

using namespace std;

class First {
protected:
    int value;

    First(int value) {
        this->value = value;
    }
};

class Second : public First {
public:
    Second(int value) : First(value) {
        cout << this->value << endl;
    }
};

int main() {
    Second obj(23);

    return 0;
}