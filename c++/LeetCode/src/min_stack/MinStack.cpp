//
// Created by dexhacker on 3/24/21.
//

#include "MinStack.h"
#include <cassert>

min_stack::MinStack::MinStack() {
}

void min_stack::MinStack::push(int val) {
    stack.push_back(val);
    if (minStack.empty()) {
        minStack.push_back(val);
    } else {
        if (minStack[minStack.size() - 1] >= val) {
            minStack.push_back(val);
        }
    }
}

void min_stack::MinStack::pop() {
    int current = stack[stack.size() - 1];
    stack.pop_back();
    if (minStack.empty()) return;

    if (minStack[minStack.size() - 1] == current) {
        minStack.pop_back();
    }
}

int min_stack::MinStack::top() {
    return stack[stack.size() - 1];
}

int min_stack::MinStack::getMin() {
    return minStack[minStack.size() - 1];
}

void min_stack::MinStack::test() {
    auto * testStack = new MinStack();
    testStack->push(-2);
    testStack->push(0);
    testStack->push(-3);
    assert(testStack->getMin() == -3);
    testStack->pop();
    assert(testStack->top() == 0);
    assert(testStack->getMin() == -2);

    cout << "MinStack completed!" << endl;
}
