//
// Created by dexhacker on 3/27/21.
//

#include "Solution.h"
#include <cassert>

int trapping_rain_water::Solution::trap(vector<int> &height) {
    if (height.size() < 3) return 0;

    int l = 0, r = 1, answer = 0;
    while (l < height.size() && r < height.size()) {
        if (height[l] > height[r]) {
            if (r + 1 < height.size()) {
                r++;
                continue;
            } else {
                int max = 0;
                int index_of_max = -1;
                for (int i = l + 1; i < height.size(); i++) {
                    if (height[i] >= max) {
                        max = height[i];
                        index_of_max = i;
                    }
                }
                for (int i = l + 1; i < index_of_max; i++) {
                    answer += max - height[i];
                }

                if (index_of_max < 0) break;
                l = index_of_max;
                r = l + 1;
                if (r >=  height.size()) break;
                continue;
            }
        }
        if (height[l] <= height[r]) {
            for (int i = l + 1; i < r; i++) {
                answer += height[l] - height[i];
            }
            l = r;
            r++;
        }
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
