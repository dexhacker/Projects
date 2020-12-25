#include <iostream>

using namespace std;

class b;

class a {
    friend int sum(a, b);
private:
    int i;
public:
    a() {
        cout << "Enter a: ";
        cin >> i;
    }
};

class b {
    friend int sum(a, b);
private:
    int y;
public:
    b() {
        cout << "Enter b: ";
        cin >> y;
    }
};

int sum(a first, b second) {
    return first.i + second.y;
}

int main() {
    a first;
    b second;
    cout << sum(first, second) << endl;

    return 0;
}