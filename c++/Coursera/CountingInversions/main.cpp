#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

long int sum = 0;

vector<int> rec(vector<int>& a) {
    if (a.size() == 1)
        return a;

    if (a.size() == 2) {
        if (a[0] < a[1]) {
            return a;
        } else {
            vector<int> result {a[1], a[0]};
            sum++;
            return result;
        }
    }

    auto left = a.begin();
    auto middle = a.begin() + a.size() / 2;
    auto right = a.begin() + a.size();

    vector<int> firstHalf(left, middle);
    vector<int> secondHalf(middle, right);
    vector<int> sortedFirstHalf, sortedSecondHalf, result;
    sortedFirstHalf = rec(firstHalf);
    sortedSecondHalf = rec(secondHalf);

    for (int i = 0, z = 0, k = 0; i < sortedFirstHalf.size() + sortedSecondHalf.size(); i++) {
        if (sortedFirstHalf[z] < sortedSecondHalf[k] && z < sortedFirstHalf.size()) {
            result.push_back(sortedFirstHalf[z]);
            z++;
        } else {
            if (k < sortedSecondHalf.size()) {
                result.push_back(sortedSecondHalf[k]);
                sum += sortedFirstHalf.size() - z;
                k++;
            } else {
                result.push_back(sortedFirstHalf[z]);
                z++;
            }
        }
    }

    return result;
}

int main() {
  vector<int> a {};
    ifstream file("../IntegerArray.txt");

    cout << "Start" << endl;
    if (file.is_open()) {
        cout << "File is open" << endl;
        string line;
        while (getline(file, line)) {
            a.push_back(atoi(line.c_str()));
        }
        file.close();
    }

    vector<int> result;
    result = rec(a);
    cout << "SUM: " << sum << endl;

    return 0;
}


