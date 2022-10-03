//
// Created by dexhacker on 10/3/22.
//

#include "Solution.h"
#include <cassert>

int minimum_time_to_make_rope_colorful::Solution::minCost(std::string colors, vector<int> &neededTime) {
    int answer = 0;
    char same;
    int maximum = 0;
    for (int i = 0; i < colors.size(); i++) {
        if (same == colors[i]) {
            if (maximum < neededTime[i]) {
                answer += maximum;
                maximum = neededTime[i];
            } else {
                answer += neededTime[i];
            }
        } else {
            same = colors[i];
            maximum = neededTime[i];
        }
    }

    return answer;
}

void minimum_time_to_make_rope_colorful::Solution::test() {
    vector<int> test1 {1, 2, 3, 4, 5};
    assert(minCost("abaac", test1) == 3);

    cout << "minCost completed!" << endl;
}
