//
// Created by dexhacker on 11/17/22.
//

#include "Solution.h"
#include <cassert>

vector<vector<int>> insert_interval::Solution::insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    if (intervals.empty()) return {newInterval};

    vector<vector<int>> answer;
    bool used = false;
    bool overlapping = false;
    int start = -1;
    int finish = -1;

    if (intervals[0][0] > newInterval[1]) {
        answer.push_back(newInterval);
        used = true;
    }

    if (intervals[0][0] <= newInterval[1] && newInterval[1] <= intervals[0][1]) {
        start = min(intervals[0][0], newInterval[0]);
        finish = max(intervals[0][1], newInterval[1]);
        overlapping = true;
    }

    for (auto & interval : intervals) {
        if (!used) {
            if (interval[1] < newInterval[0]) {
                answer.push_back(interval);
                continue;
            }

            if (interval[0] <= newInterval[0] && newInterval[0] <= interval[1]) {
                start = interval[0];
                finish = max(interval[1], newInterval[1]);
                overlapping = true;
                continue;
            }

            if (interval[0] <= newInterval[1] && newInterval[1] <= interval[1]) {
                if (start == -1) {
                    start = min (newInterval[0], interval[0]);
                } else {
                    start = min(start, newInterval[0]);
                    start = min(start, interval[0]);
                }
                finish = max(interval[1], newInterval[1]);
                overlapping = true;
                continue;
            }

            if (overlapping) {
                if (interval[0] > finish) {
                    answer.push_back({start, finish});
                    used = true;
                    answer.push_back(interval);
                } else {
                    finish = max(finish, interval[1]);
                }
                continue;
            }

            if (interval[0] > newInterval[0] && interval[1] < newInterval[1]) {
                start = newInterval[0];
                finish = newInterval[1];
                overlapping = true;
                continue;
            }

            answer.push_back(newInterval);
            answer.push_back(interval);
            used = true;
        } else {
            answer.push_back(interval);
        }
    }

    if (!used) {
        if (overlapping) {
            answer.push_back({start, finish});
        } else {
            answer.push_back(newInterval);
        }
    }
    return answer;
}

void insert_interval::Solution::test() {
    vector<vector<int>> test_intervals {{1, 3}, {6, 9}};
    vector<int> test_new_interval {2, 5};
    vector<vector<int>> answer {{1, 5}, {6, 9}};
    vector<vector<int>> result = insert(test_intervals, test_new_interval);
    for (int i = 0; i < answer.size(); i++) {
        assert(result[i][0] == answer[i][0]);
        assert(result[i][1] == answer[i][1]);
    }

    cout << "insert completed!" << endl;
}
