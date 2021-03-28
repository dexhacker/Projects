//
// Created by dexhacker on 3/24/21.
//

#ifndef LEETCODE_IMPLEMENT_QUEUE_USING_STACKS_H
#define LEETCODE_IMPLEMENT_QUEUE_USING_STACKS_H

#include <iostream>
#include <stack>

using namespace std;

namespace implement_queue_using_stacks {
    class MyQueue {
    public:
        static void test();

        MyQueue();

        void push(int x);

        int pop();

        int peek();

        bool empty();

    private:
        stack<int> stack1;
        stack<int> stack2;
    };
}

#endif //LEETCODE_IMPLEMENT_QUEUE_USING_STACKS_H
