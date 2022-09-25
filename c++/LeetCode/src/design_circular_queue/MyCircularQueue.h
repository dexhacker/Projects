//
// Created by dexhacker on 9/25/22.
//

#ifndef LEETCODE_DESIGN_CIRCULAR_QUEUE_H
#define LEETCODE_DESIGN_CIRCULAR_QUEUE_H

#include <iostream>
#include <unordered_map>

using namespace std;

namespace design_circular_queue {
    class MyCircularQueue {
    public:
        static void test();
        MyCircularQueue(int k);
        bool enQueue(int value);
        bool deQueue();
        int Front();
        int Rear();
        bool isEmpty();
        bool isFull();

    private:
        unordered_map<int, int> m;
        int min_index = 0;
        int max_index = -1;
        int m_lenght = 0;
        int total = 0;
    };
}

#endif //LEETCODE_DESIGN_CIRCULAR_QUEUE_H
