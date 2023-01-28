//
// Created by dexhacker on 1/28/23.
//

#ifndef LEETCODE_DATA_STREAM_AS_DISJOINT_INTERVALS_H
#define LEETCODE_DATA_STREAM_AS_DISJOINT_INTERVALS_H

#include <iostream>
#include <vector>

using namespace std;

namespace data_stream_as_disjoint_intervals {
    class SummaryRanges {
    private:
        bool a[10001]{};

    public:
        SummaryRanges();
        void addNum(int value);
        vector<vector<int>> getIntervals();
        static void test();
    };
}

#endif //LEETCODE_DATA_STREAM_AS_DISJOINT_INTERVALS_H
