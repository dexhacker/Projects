//
// Created by dexhacker on 9/18/22.
//

#ifndef LEETCODE_COUNT_DAYS_SPENT_TOGETHER_H
#define LEETCODE_COUNT_DAYS_SPENT_TOGETHER_H

#include <iostream>
#include <vector>

using namespace std;

namespace count_days_spent_together {
    class Solution {
    public:
        int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob);
        int get_int(int m, int d);
        void test();

    private:
        vector<int> days {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    };
}

#endif //LEETCODE_COUNT_DAYS_SPENT_TOGETHER_H
