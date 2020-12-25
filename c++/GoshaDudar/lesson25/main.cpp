#include <iostream>

using namespace std;

const int arr_length = 3;

template <class Type>
class Arr {
private:
    Type arr[arr_length];
public:
    Arr(Type* a) {
        for (int i = 0; i < arr_length; i++)
            arr[i] = a[i];
    }

    Type getElement(int i) {
        return arr[i];
    }
};

int main() {
    int arr[] = {12, 23, 45, 6};
    Arr<int> obj(arr);
    cout << obj.getElement(2) << endl;

    char arr2[] = {"qwerty"};
    Arr<char> obj2(arr2);
    cout << obj2.getElement(2) << endl;

    return 0;
}
