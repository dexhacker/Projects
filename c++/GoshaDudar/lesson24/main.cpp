#include <iostream>

using namespace std;

template <typename T1, typename T2>
T2 printArr(const T1 * array, int i) {
    int count = 0;
    for (int j = 0; j < i; j++) {
        cout << array[j] << " ";
        count++;
    }
    cout << endl;
    return count;
}

int main() {
    const int iSize = 3, fSize = 2, dSize = 3, cSize = 5;

    int i_arr[iSize] = {23, 45, 78};
    float f_arr[fSize] = {12.2, 67.5};
    double d_arr[dSize] = {3.345, 7.567, 9.023};
    char c_arr[cSize] = {"HI!!"};

    cout << "Массив с типом данных int: ";
    cout << "Количество элементов: " << printArr<int, int>(i_arr, iSize) << endl;

    cout << "Массив с типом данных float: ";
    cout << "Количество элементов: " << printArr<float, int>(f_arr, fSize) << endl;

    cout << "Массив с типом данных double: ";
    cout << "Количество элементов: " << printArr<double, int>(d_arr, dSize) << endl;

    cout << "Массив с типом данных char: ";
    cout << "Количество элементов: " << printArr<char, int>(c_arr, cSize) << endl;

    return 0;
}