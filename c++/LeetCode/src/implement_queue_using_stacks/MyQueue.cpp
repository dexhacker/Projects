//
// Created by dexhacker on 3/24/21.
//

#include "MyQueue.h"
#include <cassert>

implement_queue_using_stacks::MyQueue::MyQueue() {}

void implement_queue_using_stacks::MyQueue::push(int x) {
    if (stack1.empty()) {
        stack1.push(x);
    } else {
        stack2 = {};
        while (!(stack1.empty())) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1 = {};
        stack1.push(x);
        while (!(stack2.empty())) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
}

int implement_queue_using_stacks::MyQueue::pop() {
    int element = stack1.top();
    stack1.pop();
    return element;
}

int implement_queue_using_stacks::MyQueue::peek() {
    return stack1.top();
}

bool implement_queue_using_stacks::MyQueue::empty() {
    return stack1.empty();
}

void implement_queue_using_stacks::MyQueue::test() {
    auto * myQueue = new MyQueue();
    myQueue->push(1);
    myQueue->push(2);
    assert(myQueue->peek() == 1);
    assert(myQueue->pop() == 1);
    assert(myQueue->empty() == false);

    auto * myQueue2 = new MyQueue();
    myQueue2->push(1);
    myQueue2->push(2);
    myQueue2->push(3);
    myQueue2->push(4);
    assert(myQueue2->pop() == 1);
    myQueue2->push(5);
    assert(myQueue2->pop() == 2);
    assert(myQueue2->pop() == 3);
    assert(myQueue2->pop() == 4);
    assert(myQueue2->pop() == 5);

    cout << "MyQueue completed!" << endl;
}
