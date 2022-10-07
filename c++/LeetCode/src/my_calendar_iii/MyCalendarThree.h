//
// Created by Фарид Абдугалыев on 07.10.2022.
//

#ifndef LEETCODE_MY_CALENDAR_III_H
#define LEETCODE_MY_CALENDAR_III_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace my_calendar_iii {
    class MyCalendarThree {
    public:
        static void test();
        MyCalendarThree();
        int book(int start, int end);

    private:
        vector<pair<int, int>> numbers;
        unordered_map<int, int> m;
    };
}

#endif //LEETCODE_MY_CALENDAR_III_H
