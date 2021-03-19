//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>
#include <set>

vector<vector<int>> merge_intervals::Solution::merge(vector<vector<int>> &intervals) {
    unordered_map<int, int> hash_map;
    set<int> starts;
    vector<vector<int>> answer;

    for (int i = 0; i < intervals.size(); i++) {
        starts.insert(intervals[i][0]);
        if (hash_map.find(intervals[i][0]) != hash_map.end()) {
            if (hash_map[intervals[i][0]] < intervals[i][1])
                hash_map[intervals[i][0]] = intervals[i][1];
        } else {
            hash_map[intervals[i][0]] = intervals[i][1];
        }
    }

    set<int>::iterator it = starts.begin();
    int start = *it;
    int max = hash_map[start];
    it++;
    while (it != starts.end()) {
        if (*it > max) {
            answer.push_back({start, max});
            start = *it;
            max = hash_map[start];
        }

        if (hash_map[*it] > max) max = hash_map[*it];

        it++;
    }
    answer.push_back({start, max});
    return answer;
}

void merge_intervals::Solution::test() {
    vector<vector<int>> test1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> answer1 = {{1, 6}, {8, 10}, {15, 18}};
    assert(merge(test1) == answer1);

    vector<vector<int>> test2 = {{1, 4}, {4, 5}};
    vector<vector<int>> answer2 = {{1, 5}};
    assert(merge(test2) == answer2);

    vector<vector<int>> test3 = {{1, 4}, {0, 4}};
    vector<vector<int>> answer3 = {{0, 4}};
    assert(merge(test3) == answer3);

    vector<vector<int>> test4 = {{2, 3}, {5, 5}, {2, 2}, {3, 4}, {3, 4}};
    vector<vector<int>> answer4 = {{2, 4}, {5, 5}};
    assert(merge(test4) == answer4);

    std::cout << "merge completed!" << std::endl;
}
