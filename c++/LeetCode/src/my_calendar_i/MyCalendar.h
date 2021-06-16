//
// Created by dexhacker on 6/10/21.
//

#ifndef LEETCODE_MY_CALENDAR_I_H
#define LEETCODE_MY_CALENDAR_I_H

#include <iostream>
#include <vector>

using namespace std;

namespace my_calendar_i {
    class MyCalendar {
    public:
        static void test();
        MyCalendar();
        bool book(int start, int end);

    private:
        vector<pair<int, int>> books;
    };
}

#endif //LEETCODE_MY_CALENDAR_I_H
