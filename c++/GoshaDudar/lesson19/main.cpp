#include <iostream>

using namespace std;

class Auto {
private:
    int year, month, day;

public:
    int value1 = 10;

    Auto() {
        year = 2000;
        month = 12;
        day = 31;

        get();
    }

    Auto(int date_year, int date_month, int date_day) {
        year = date_year;
        month = date_month;
        day = date_day;

        get();
    }

    void message() {
        cout << "Value: " << value1 << endl;
    }

    void set(int date_year, int date_month, int date_day) {
        year = date_year;
        month = date_month;
        day = date_day;
    }

    void get() {
        cout << "Year of this auto is - " << year << ", month is - " << month << ", day is - " << day << endl;
    }

    ~Auto() {
        cout << "Class finished" << endl;
    }
};

int main() {
    Auto shkoda(2010, 2, 18);
    shkoda.message();
    shkoda.set(2005, 11, 23);
    shkoda.get();

    Auto bmw;
    bmw.set(2012, 1, 1);
    bmw.get();

    return 0;
}