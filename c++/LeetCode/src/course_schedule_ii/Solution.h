//
// Created by Фарид Абдугалыев on 23.12.2021.
//

#ifndef LEETCODE_COURSE_SCHEDULE_II_H
#define LEETCODE_COURSE_SCHEDULE_II_H

#include <iostream>
#include <vector>

using namespace std;

namespace course_schedule_ii {
    class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
        void test();
    };
}

#endif //LEETCODE_COURSE_SCHEDULE_II_H
