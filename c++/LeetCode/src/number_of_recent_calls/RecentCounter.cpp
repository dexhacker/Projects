//
// Created by dexhacker on 3/25/21.
//

#include "RecentCounter.h"
#include <cassert>

number_of_recent_calls::RecentCounter::RecentCounter() {}

int number_of_recent_calls::RecentCounter::ping(int t) {
    from_second = t - 3000;
    if (list.empty()) {
        list.push(t);
    } else {
        while (!(list.empty()) && list.front() < from_second) {
            list.pop();
        }
        list.push(t);
    }
    return list.size();
}

void number_of_recent_calls::RecentCounter::test() {
    auto * tes1 = new RecentCounter();
    assert(tes1->ping(1) == 1);
    assert(tes1->ping(100) == 2);
    assert(tes1->ping(3001) == 3);
    assert(tes1->ping(3002) == 3);

    std::cout << "RecentCounter completed!" << std::endl;
}
