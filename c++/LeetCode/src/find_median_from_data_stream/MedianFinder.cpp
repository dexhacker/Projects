//
// Created by dexhacker on 4/22/21.
//

#include "MedianFinder.h"
#include <cassert>

find_median_from_data_stream::MedianFinder::MedianFinder() {}

void find_median_from_data_stream::MedianFinder::addNum(int num) {
    size++;
    if (head) {
        if (head->val > num) {
            auto tmp = head;
            head = new ListNode(num);
            head->next = tmp;
        } else {
            auto current = head;
            while (current->next) {
                if (current->next->val >= num) {
                    auto new_node = new ListNode(num);
                    auto tmp = current->next;
                    current->next = new_node;
                    new_node->next = tmp;
                    return;
                }
                current = current->next;
            }
            auto new_node = new ListNode(num);
            current->next = new_node;
        }
    } else {
        head = new ListNode(num);
    }
}

double find_median_from_data_stream::MedianFinder::findMedian() {
    auto current = head;
    int counter = 0;
    while (current) {
        if (size % 2 == 1) {
            if (counter == size / 2) return current->val;
        } else {
            if (counter == size / 2 - 1) return (current->val + current->next->val) / 2.0;
        }
        current = current->next;
        counter++;
    }

    return 0;
}

void find_median_from_data_stream::MedianFinder::test() {
    auto test1 = new MedianFinder();
    test1->addNum(1);
    test1->addNum(2);
    assert(test1->findMedian() == 1.5);
    test1->addNum(3);
    assert(test1->findMedian() == 2);

    auto test2 = new MedianFinder();
    test2->addNum(6);
    assert(test2->findMedian() == 6);
    test2->addNum(10);
    assert(test2->findMedian() == 8);
    test2->addNum(2);
    assert(test2->findMedian() == 6);
    test2->addNum(6);
    assert(test2->findMedian() == 6);
    test2->addNum(5);
    assert(test2->findMedian() == 6);
    test2->addNum(0);
    assert(test2->findMedian() == 5.5);
    test2->addNum(6);
    assert(test2->findMedian() == 6);
    test2->addNum(3);
    assert(test2->findMedian() == 5.5);
    test2->addNum(1);
    assert(test2->findMedian() == 5);
    test2->addNum(0);
    assert(test2->findMedian() == 4);
    test2->addNum(0);
    assert(test2->findMedian() == 3);

    cout << "MedianFinder completed!" << endl;
}
