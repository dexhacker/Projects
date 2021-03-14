#include <vector>
#include <iostream>

using namespace std;

vector<int> rec(vector<int>& a) {
    if (a.size() == 1)
        return a;

    if (a.size() == 2) {
        if (a[0] < a[1]) {
            return a;
        } else {
            vector<int> result {a[1], a[0]};
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
            result.push_back(sortedSecondHalf[k]);
            k++;
        }
    }


    return result;
}

int main() {
    vector<int> a {2, 6, 8, 3, 1, 7, 4, 9};
    vector<int> result;
    result = rec(a);
    for (int i : result) {
        cout << i << endl;
    }

    return 0;
}
