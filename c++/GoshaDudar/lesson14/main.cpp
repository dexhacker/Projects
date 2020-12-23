#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * args[]) {
//    ofstream file("text.txt");
//    file << "Work with files in C++";
//    file.close();

    char text[50];

    ifstream file("text.txt");
    if (!file.is_open())
        cout << "Error! File is not found!" << endl;
    else {
//        file >> text;
//        cout << text << endl;

        file.getline(text, 50);
        cout << text << endl;
        file.close();
    }

    return 0;
}