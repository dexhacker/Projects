//
// Created by dexhacker on 6/10/21.
//

#include "MyCalendar.h"
#include <cassert>

my_calendar_i::MyCalendar::MyCalendar() {}

bool my_calendar_i::MyCalendar::book(int start, int end) {
    for (pair<int, int> p : books)
        if (max(p.first, start) < min(end, p.second)) return false;
    books.emplace_back(start, end);
    return true;
}

void my_calendar_i::MyCalendar::test() {
    auto my_calendar = new MyCalendar();
    assert(my_calendar->book(10, 20) == true);
    assert(my_calendar->book(15, 25) == false);
    assert(my_calendar->book(20, 30) == true);

    cout << "book completed!" << endl;
}
