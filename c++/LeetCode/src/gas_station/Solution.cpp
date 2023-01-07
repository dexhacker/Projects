//
// Created by dexhacker on 1/7/23.
//

#include "Solution.h"
#include <cassert>

int gas_station::Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int sum = 0;
    int sub_sum = 0;
    int answer = -1;
    for (int i = 0; i < gas.size(); i++) {
        sum += gas[i] - cost[i];
        if (answer == -1 && gas[i] - cost[i] >= 0) {
            answer = i;
            sub_sum += gas[i] - cost[i];
            continue;
        }

        if (answer == -1) continue;

        sub_sum += gas[i] - cost[i];
        while (sub_sum < 0) {
            if (answer == i) {
                answer = -1;
                sub_sum = 0;
                break;
            }
            sub_sum -= gas[answer] - cost[answer];
            answer++;
        }
    }
    return (sum >= 0) ? answer : -1;
}

void gas_station::Solution::test() {
    vector<int> gas {1, 2, 3, 4, 5};
    vector<int> cost {3, 4, 5, 1, 2};
    assert(canCompleteCircuit(gas, cost) == 3);

    cout << "canCompleteCircuit completed!" << endl;
}
