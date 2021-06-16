//
// Created by dexhacker on 6/14/21.
//

#include "Solution.h"
#include <cassert>

int maximum_units_on_a_truck::Solution::maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    vector<pair<int, int>> pairs;
    for (auto p : boxTypes) pairs.push_back({p[1], p[0]});
    sort(pairs.begin(), pairs.end(), greater <>());

    int answer = 0;
    for (auto p : pairs) {
        if (truckSize <= p.second) answer += truckSize * p.first;
        if (truckSize > p.second) {
            answer += p.second * p.first;
        }
        truckSize -= p.second;
        if (truckSize < 1) return answer;
    }
    return answer;
}

void maximum_units_on_a_truck::Solution::test() {
    vector<vector<int>> test {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    assert(maximumUnits(test, 10) == 91);

    cout << "maximumUnits completed!" << endl;
}
