//
// Created by dexhacker on 5/27/21.
//

#ifndef LEETCODE_COURSE_SCHEDULE_H
#define LEETCODE_COURSE_SCHEDULE_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace course_schedule {
    class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
        void dfs(int key, vector<int> & neighbors, unordered_map<int, bool> visited);
        void test();

    private:
        unordered_map<int, vector<int>> adjastancy_map;
        unordered_map<int, bool> used;
        bool answer = true;
    };
}

#endif //LEETCODE_COURSE_SCHEDULE_H
