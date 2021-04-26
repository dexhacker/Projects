//
// Created by dexhacker on 4/22/21.
//

#ifndef LEETCODE_FIND_MEDIAN_FROM_DATA_STREAM_H
#define LEETCODE_FIND_MEDIAN_FROM_DATA_STREAM_H

#include <iostream>
#include "../ListNode.h"

using namespace std;

namespace find_median_from_data_stream {
    class MedianFinder {
    public:
        static void test();

        MedianFinder();
        void addNum(int num);
        double findMedian();

    private:
        ListNode* head = nullptr;
        int size = 0;
    };
}

#endif //LEETCODE_FIND_MEDIAN_FROM_DATA_STREAM_H
