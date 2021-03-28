//
// Created by dexhacker on 3/25/21.
//

#ifndef LEETCODE_NUMBER_OF_RECENT_CALLS_H
#define LEETCODE_NUMBER_OF_RECENT_CALLS_H

#include <iostream>
#include <queue>

using namespace std;

namespace number_of_recent_calls {
    class RecentCounter {
    public:
        static void test();
        RecentCounter();
        int ping(int t);

    private:
        int from_second;
        queue<int> list;
    };
}

#endif //LEETCODE_NUMBER_OF_RECENT_CALLS_H
