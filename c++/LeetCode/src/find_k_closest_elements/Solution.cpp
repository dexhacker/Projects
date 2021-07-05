//
// Created by dexhacker on 7/2/21.
//

#include "Solution.h"
#include <cassert>

int find_k_closest_elements::Solution::closestIndex(vector<int> &arr, int x, int start, int finish) {
    int middle = (start + finish) / 2;
    if (arr[middle] == x) return middle;
    if (arr[middle] > x) {
        if (middle == 0) return middle;

        if (arr[middle - 1] < x and x < arr[middle]) {
            if (abs(x - arr[middle]) > abs(x - arr[middle - 1])) {
                return middle - 1;
            } else {
                return middle;
            }
        }

        return closestIndex(arr, x, 0, middle - 1);
    } else {
        if (middle == arr.size() - 1) return middle;


        if (arr[middle] < x and x < arr[middle + 1]) {
            if (abs(x - arr[middle]) > abs(x - arr[middle + 1])) {
                return middle + 1;
            } else {
                return middle;
            }
        }

        return closestIndex(arr, x, middle + 1, finish);
    }
}

vector<int> find_k_closest_elements::Solution::findClosestElements(vector<int> &arr, int k, int x) {
    vector<int> answer;
    int index = closestIndex(arr, x, 0, arr.size() - 1);
    int l = index - 1;
    int r = index + 1;
    answer.push_back(arr[index]);

    --k;
    while (k > 0) {
        if ((l < 0) or ((r < arr.size()) and (abs(x - arr[l]) > abs(x - arr[r])))) {
            answer.push_back(arr[r]);
            ++r;
        } else {
            answer.push_back(arr[l]);
            --l;
        }
        --k;
    }
    sort(answer.begin(), answer.end());
    return answer;
}

void find_k_closest_elements::Solution::test() {
    vector<int> test {1, 2, 3, 4, 5};
    vector<int> answer {1, 2, 3, 4};
    assert(findClosestElements(test, 4, 3) == answer);

    cout << "findClosestElements completed!" << endl;
}
