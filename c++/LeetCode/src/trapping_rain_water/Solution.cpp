//
// Created by dexhacker on 3/27/21.
//

#include "Solution.h"
#include <cassert>

int trapping_rain_water::Solution::trap(vector<int> &height) {
    vector<int> max_l(height.size(), 0);
    vector<int> max_r(height.size(), 0);

    int maximum = 0;
    for (int i = 0; i < height.size(); i++) {
        if (height[i] > maximum) maximum = height[i];
        max_l[i] = maximum;
    }

    maximum = 0;
    for (int i = height.size() - 1; i >= 0; i--) {
        if (height[i] > maximum) maximum = height[i];
        max_r[i] = maximum;
    }

    int answer = 0;
    for (int i = 0; i < height.size(); i++) {
        answer += min(max_l[i], max_r[i]) - height[i];
    }

    return answer;
}

void trapping_rain_water::Solution::test() {
    vector<int> test1 {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(trap(test1) == 6);

    vector<int> test2 {4, 2, 0, 3, 2, 5};
    assert(trap(test2) == 9);

    vector<int> test3 {0};
    assert(trap(test3) == 0);

    vector<int> test4 {4, 2, 3};
    assert(trap(test4) == 1);

    vector<int> test5 {2, 1, 0, 2};
    assert(trap(test5) == 3);

    cout << "trap completed!" << endl;
}
