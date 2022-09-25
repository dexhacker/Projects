//
// Created by dexhacker on 9/25/22.
//

#include "MyCircularQueue.h"
#include <cassert>

design_circular_queue::MyCircularQueue::MyCircularQueue(int k) {
    total = k;
}

bool design_circular_queue::MyCircularQueue::enQueue(int value) {
    if (isFull()) return false;

    max_index++;
    m[max_index] = value;
    m_lenght++;
    return true;
}

bool design_circular_queue::MyCircularQueue::deQueue() {
    if (isEmpty()) return false;

    m_lenght--;
    m.erase(min_index);
    min_index++;
    return true;
}

int design_circular_queue::MyCircularQueue::Front() {
    if (m_lenght > 0) {
        return m[min_index];
    } else {
        return -1;
    }
}

int design_circular_queue::MyCircularQueue::Rear() {
    if (m_lenght > 0) {
        return m[max_index];
    } else {
        return -1;
    }
}

bool design_circular_queue::MyCircularQueue::isEmpty() {
    return m_lenght == 0;
}

bool design_circular_queue::MyCircularQueue::isFull() {
    return m_lenght == total;
}

void design_circular_queue::MyCircularQueue::test() {
    auto my_circular_queue = new MyCircularQueue(3);
    assert(my_circular_queue->enQueue(1) == true);
    assert(my_circular_queue->enQueue(2) == true);
    assert(my_circular_queue->enQueue(3) == true);
    assert(my_circular_queue->enQueue(4) == false);
    assert(my_circular_queue->Rear() == 3);
    assert(my_circular_queue->isFull() == true);
    assert(my_circular_queue->deQueue() == true);
    assert(my_circular_queue->enQueue(4) == true);
    assert(my_circular_queue->Rear() == 4);

    cout << "MyCircularQueue completed!" << endl;
}
