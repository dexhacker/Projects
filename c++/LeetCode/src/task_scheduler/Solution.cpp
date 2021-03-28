//
// Created by dexhacker on 3/26/21.
//

#include "Solution.h"
#include <cassert>

int task_scheduler::Solution::leastInterval(vector<char> &tasks, int n) {
    int a[26] = {};
    int max = 0;
    int equal = 0;
    for (auto c : tasks) {
        a[c - 'A']++;
        if (max == a[c - 'A']) equal++;
        if (max < a[c - 'A']) {
            max = a[c - 'A'];
            equal = 1;
        }
    }
    int answer = (max - 1) * (n + 1) + 1 * equal;
    return (answer > tasks.size()) ? answer : tasks.size();
}

void task_scheduler::Solution::test() {
    vector<char> test1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    assert(leastInterval(test1, 2) == 8);

    vector<char> test2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    assert(leastInterval(test2, 0) == 6);

    vector<char> test3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    assert(leastInterval(test3, 2) == 16);

    vector<char> test4 = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E'};
    assert(leastInterval(test4, 2) == 12);

    vector<char> test5 = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C'};
    assert(leastInterval(test5, 2) == 9);

    cout << "leastInterval completed!" << endl;
}
