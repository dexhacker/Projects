//
// Created by dexhacker on 10/31/22.
//

#include "Solution.h"
#include <numeric>
#include <cassert>

int earliest_possible_day_of_full_bloom::Solution::earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
    vector<int> indices(plantTime.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&](int i, int j) { return growTime[i] > growTime[j]; });
    int result = 0, curPlantTime = 0;
    for (int i : indices) {
        curPlantTime += plantTime[i];
        result = max(result, curPlantTime + growTime[i]);
    }
    return result;
}

void earliest_possible_day_of_full_bloom::Solution::test() {
    vector<int> test1 {1, 4, 3};
    vector<int> test2 {2, 3, 1};
    assert(earliestFullBloom(test1, test2) == 9);

    cout << "earliestFullBloom completed!" << endl;
}
