//
// Created by dexhacker on 6/11/21.
//

#include "Solution.h"
#include <cassert>

int container_with_most_water::Solution::maxArea(vector<int> &height) {
    vector<int> l_max {0};
    vector<int> r_max {(int)(height.size() - 1)};
    int answer = 0;
    for (int i = 1; i < height.size() - 1; i++) {
        if (height[i] > height[l_max.back()]) l_max.push_back(i);
    }

    for (int i = height.size() - 2; i > 0; i--) {
        if (height[i] > height[r_max.back()]) r_max.push_back(i);
    }

    for (int i : l_max) {
        for (int j : r_max) {
            if (j <= i) break;
            int area = (j - i) * min(height[i], height[j]);
            answer = max(answer, area);
        }
    }
    return answer;
}

void container_with_most_water::Solution::test() {
    vector<int> test {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(maxArea(test) == 49);

    cout << "maxArea completed!" << endl;
}
