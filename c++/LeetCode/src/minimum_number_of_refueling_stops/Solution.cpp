//
// Created by dexhacker on 6/13/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int minimum_number_of_refueling_stops::Solution::minRefuelStops(int target, int startFuel,
                                                                vector<vector<int>> &stations) {
    int i = 0, res;
    priority_queue<int>pq;
    for (res = 0; startFuel < target; res++) {
        while (i < stations.size() && stations[i][0] <= startFuel)
            pq.push(stations[i++][1]);
        if (pq.empty()) return -1;
        startFuel += pq.top(), pq.pop();
    }
    return res;
}

void minimum_number_of_refueling_stops::Solution::test() {
    vector<vector<int>> test {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    assert(minRefuelStops(100, 10, test) == 2);

    cout << "minRefuelStops completed!" << endl;
}
