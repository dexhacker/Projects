#include <iostream>

using namespace std;

struct Date {
    int year;
};

struct Auto {
    int wheels;
    float speed;
    char color;

    Date createdAt;
};

int main(int argc, const char * argv[]) {
    Auto shkoda;
    shkoda.color = 'r';
    shkoda.speed = 315.23;
    shkoda.wheels = 4;
    shkoda.createdAt.year = 1995;

    Auto audi = {4, 300.23, 'b' };
    cout << "AUDI speed = " << audi.speed << "\n" << "Shkoda year = " << shkoda.createdAt.year << endl;

    return 0;
}