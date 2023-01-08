//
// Created by dexhacker on 1/8/23.
//

#include "Solution.h"
#include <unordered_map>
#include <climits>
#include <cassert>

int max_points_on_a_line::Solution::maxPoints(vector<vector<int>> &points) {
    int n = points.size();
    if(n <= 2) return n;
    int ans = 0;

    for(auto it1 : points){
        unordered_map<double,int> mp;
        double x1 = it1[0], y1 = it1[1];
        for(auto it2 : points){
            if (it2 == it1) continue;
            double x2 = it2[0], y2 = it2[1];
            double slope;
            if (x2 - x1 == 0){
                slope = INT_MAX;
            } else {
                slope = (y2 - y1) / (x2 - x1);
            }
            mp[slope]++;
            ans = max(ans, mp[slope]);
        }
    }
    return ans + 1;
}

void max_points_on_a_line::Solution::test() {
    vector<vector<int>> points {{1, 1}, {2, 2}, {3, 3}};
    assert(maxPoints(points) == 3);

    cout << "maxPoints completed!" << endl;
}
