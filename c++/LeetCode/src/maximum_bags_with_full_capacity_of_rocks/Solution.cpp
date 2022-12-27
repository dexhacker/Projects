//
// Created by dexhacker on 12/27/22.
//

#include "Solution.h"
#include <cassert>

int maximum_bags_with_full_capacity_of_rocks::Solution::maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
    vector<int> needRocks;
    int answer = 0;
    for (int i = 0; i < rocks.size(); i++) {
        int diff = capacity[i] - rocks[i];
        if (diff == 0) {
            answer++;
        } else {
            needRocks.push_back(diff);
        }
    }
    sort(needRocks.begin(), needRocks.end());
    for (int i : needRocks) {
        additionalRocks -= i;
        if (additionalRocks < 0) break;
        answer++;
    }
    return answer;
}

void maximum_bags_with_full_capacity_of_rocks::Solution::test() {
    vector<int> capacity {2, 3, 4, 5};
    vector<int> rocks {1, 2, 4, 4};
    assert(maximumBags(capacity, rocks, 2) == 3);

    cout << "maximumBags completed!" << endl;
}
