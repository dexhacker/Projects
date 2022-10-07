//
// Created by Фарид Абдугалыев on 07.10.2022.
//

#include "MyCalendarThree.h"
#include <cassert>

my_calendar_iii::MyCalendarThree::MyCalendarThree() {}

int my_calendar_iii::MyCalendarThree::book(int start, int end) {
    numbers.push_back({start, end});

    for (auto p : m) {
        if (start < p.first && p.first < end) m[p.first]++;
    }

    int answer_start = 0;
    int answer_end = 0;
    for (auto p : numbers) {
        if (p.first <= start && start < p.second) answer_start++;
        if (p.first < end && end <= p.second) answer_end++;
    }

    if (m.count(start) > 0) {
        m[start] = max(m[start], answer_start);
    } else {
        m[start] = answer_start;
    }

    if (m.count(end) > 0) {
        m[end] = max(m[end], answer_end);
    } else {
        m[end] = answer_end;
    }

    int answer = 0;
    for (auto p : m) {
        answer = max(answer, p.second);
    }

    return answer;
}

void my_calendar_iii::MyCalendarThree::test() {
    auto myCalendarThree = new MyCalendarThree();
    assert(myCalendarThree->book(10, 20) == 1);
    assert(myCalendarThree->book(50, 60) == 1);
    assert(myCalendarThree->book(10, 40) == 2);
    assert(myCalendarThree->book(5, 15) == 3);
    assert(myCalendarThree->book(5, 10) == 3);
    assert(myCalendarThree->book(25, 55) == 3);

    cout << "MyCalendarThree completed!" << endl;
}
