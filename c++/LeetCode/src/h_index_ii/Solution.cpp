//
// Created by dexhacker on 4/21/21.
//

#include "Solution.h"
#include <cassert>

int h_index_ii::Solution::hIndex(vector<int> &citations) {
    int l = 0, r = citations.size() - 1;
    int answer = 0;
    while (l <= r) {
        int middle = (l + r) / 2;
        if (citations[middle] >= citations.size() - middle) {
            if (answer < citations.size() - middle) answer = citations.size() - middle;
            r = middle - 1;
        } else {
            l = middle + 1;
        }
    }
    return answer;
}

void h_index_ii::Solution::test() {
    vector<int> test1 {0, 1, 3, 5, 6};
    assert(hIndex(test1) == 3);

    vector<int> test2 {0, 2, 100};
    assert(hIndex(test2) == 2);

    vector<int> test3 {1};
    assert(hIndex(test3) == 1);

    vector<int> test4 {100};
    assert(hIndex(test4) == 1);

    vector<int> test5 {0, 1};
    assert(hIndex(test5) == 1);

    cout << "hIndex completed!" << endl;
}
