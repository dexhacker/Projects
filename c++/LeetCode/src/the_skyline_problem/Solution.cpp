//
// Created by dexhacker on 9/30/22.
//

#include "Solution.h"
#include <set>
#include <cassert>

vector<vector<int>> the_skyline_problem::Solution::getSkyline(vector<vector<int>> &buildings) {
    vector<pair<int, int>> walls;
    vector<vector<int>> ans;
    for (auto b : buildings) {
        walls.push_back(make_pair(b[0], -b[2]));
        walls.push_back(make_pair(b[1], b[2]));
    }
    sort(walls.begin(), walls.end());

    multiset<int> leftWallHeights = {0};
    int top = 0;
    for (auto w : walls) {
        if (w.second < 0) {
            leftWallHeights.insert(-w.second);
        } else {
            leftWallHeights.erase(leftWallHeights.find(w.second));
        }

        if (*leftWallHeights.rbegin() != top) {
            ans.push_back({w.first, top = *leftWallHeights.rbegin()});
        }
    }

    return ans;
}

void the_skyline_problem::Solution::test() {
    vector<vector<int>> test1 {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> answer1 {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}};
    assert(getSkyline(test1) == answer1);

    cout << "getSkyline completed!" << endl;
}
