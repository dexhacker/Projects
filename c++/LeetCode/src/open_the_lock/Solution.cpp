//
// Created by dexhacker on 6/4/21.
//

#include "Solution.h"
#include <unordered_map>
#include <queue>
#include <cassert>

string open_the_lock::Solution::modify(string s, int pos, string direction) {
    int number = s[pos] - '0';
    if (direction == "up" and number == 9) number = 0;
    else if (direction == "down" and number == 0) number = 9;
    else if (direction == "up") number++;
    else number--;
    s[pos] = number + '0';
    return s;
}

int open_the_lock::Solution::openLock(vector<string> &deadends, string target) {
    unordered_map<string, bool> used;
    vector<string> direction {"up", "down"};
    queue<pair<string, int>> q;
    q.push({"0000", 0});
    for (auto s : deadends) {
        if (s == "0000") return -1;
        used[s] = true;
    }

    while (!q.empty()) {
        auto current_pair = q.front();
        if (current_pair.first == target) return current_pair.second;

        q.pop();
        for (auto d : direction) {
            for (int i = 0; i < 4; i++) {
                string tmp = modify(current_pair.first, i, d);
                if (used[tmp]) continue;
                used[tmp] = true;
                q.push({modify(current_pair.first, i, d), current_pair.second + 1});
            }
        }
    }
    return -1;
}

void open_the_lock::Solution::test() {
    vector<string> test {"0201", "0101", "0102", "1212", "2002"};
    assert(openLock(test, "0202") == 6);

    cout << "openLock completed!" << endl;
}
