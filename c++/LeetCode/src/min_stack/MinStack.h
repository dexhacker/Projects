//
// Created by dexhacker on 3/24/21.
//

#ifndef LEETCODE_MIN_STACK_H
#define LEETCODE_MIN_STACK_H

#include <iostream>
#include <vector>

using namespace std;

namespace min_stack {
    class MinStack {
    public:
        static void test();
        MinStack();
        void push(int val);
        void pop();
        int top();
        int getMin();

    private:
        vector<int> stack;
        vector<int> minStack;
    };
}


#endif //LEETCODE_MIN_STACK_H
