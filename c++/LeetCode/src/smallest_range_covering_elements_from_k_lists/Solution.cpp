//
// Created by dexhacker on 4/16/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>

vector<int> smallest_range_covering_elements_from_k_lists::Solution::smallestRange(vector<vector<int>> &nums) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            pairs.push_back(make_pair(nums[i][j], i));
        }
    }

    sort(pairs.begin(), pairs.end());

    unordered_map<int, int> hash_map;

    for (int i = 0; i < nums.size(); i++) {
        hash_map[i] = 0;
    }

    for (int i = 0; i < nums.size(); i++) {
        hash_map[pairs[i].second]++;
    }

    int l = 0;
    int r = l + nums.size() - 1;
    int min_l = 0, min_r = 0, min = pairs[pairs.size() - 1].first - pairs[0].first + 1;
    while (l < pairs.size() && r < pairs.size()) {
        bool fill = true;
        for (auto const & [key, value] : hash_map) {
            if (value == 0) {
                fill = false;
                break;
            }
        }
        if (fill) {
            if (min > pairs[r].first - pairs[l].first) {
                min = pairs[r].first - pairs[l].first;
                min_l = l;
                min_r = r;
            }
            hash_map[pairs[l].second]--;
            l++;
        } else {
            r++;
            if (r < pairs.size()) hash_map[pairs[r].second]++;
        }
    }
    return {pairs[min_l].first, pairs[min_r].first};
}

void smallest_range_covering_elements_from_k_lists::Solution::test() {
    vector<vector<int>> test1 = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> answer1 {20, 24};
    assert(smallestRange(test1) == answer1);

    vector<vector<int>> test2 = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    vector<int> answer2 {1, 1};
    assert(smallestRange(test2) == answer2);

    vector<vector<int>> test3 = {{10, 10}, {11, 11}};
    vector<int> answer3 {10, 11};
    assert(smallestRange(test3) == answer3);

    vector<vector<int>> test4 = {{10}, {11}};
    vector<int> answer4 {10, 11};
    assert(smallestRange(test4) == answer4);

    vector<vector<int>> test5 = {{1}, {2}, {3}, {4}, {5}, {6}, {7}};
    vector<int> answer5 {1, 7};
    assert(smallestRange(test5) == answer5);

    vector<vector<int>> test6 = {{47, 67, 82, 97}, {-2, 34, 42, 49, 50, 50, 51}, {-61, -45, -3, -1, 2, 10}, {25, 57, 76, 77, 78}, {-11, 10, 29, 55, 55, 55, 57, 59, 60, 60, 62, 63}};
    vector<int> answer6 {10, 47};
    assert(smallestRange(test6) == answer6);

    cout << "smallestRange completed!" << endl;
}
