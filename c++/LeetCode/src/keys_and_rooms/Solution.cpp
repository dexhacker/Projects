//
// Created by dexhacker on 12/20/22.
//

#include "Solution.h"
#include <queue>
#include <cassert>

bool keys_and_rooms::Solution::canVisitAllRooms(vector<vector<int>> &rooms) {
    queue<int> q;
    vector<int> used(rooms.size(), false);
    q.push(0);
    while (!q.empty()) {
        int current = q.front();
        used[current] = true;
        q.pop();
        for (int i : rooms[current]) if (used[i] == false) q.push(i);
    }
    for (bool b : used) if (b == false) return false;
    return true;
}

void keys_and_rooms::Solution::test() {
    vector<vector<int>> test {{1, 3}, {3, 0, 1}, {2}, {0}};
    assert(canVisitAllRooms(test) == false);

    cout << "canVisitAllRooms completed!" << endl;
}
