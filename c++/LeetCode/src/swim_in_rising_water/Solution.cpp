//
// Created by dexhacker on 6/21/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int swim_in_rising_water::Solution::swimInWater(vector<vector<int>> &grid) {
    int N = grid.size (), res = 0;
    priority_queue<T> pq;
    pq.push(T(grid[0][0], 0, 0));
    vector<vector<int>> seen(N, vector<int>(N, 0));
    seen[0][0] = 1;
    static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

    while (true) {
        auto p = pq.top ();
        pq.pop ();
        res = max(res, p.t);
        if (p.x == N - 1 && p.y == N - 1) return res;
        for (auto& d : dir) {
            int i = p.x + d[0], j = p.y + d[1];
            if (i >= 0 && i < N && j >= 0 && j < N && !seen[i][j]) {
                seen[i][j] = 1;
                pq.push (T(grid[i][j], i, j));
            }
        }
    }
}

void swim_in_rising_water::Solution::test() {
    vector<vector<int>> test {
            {0, 1, 2, 3, 4},
            {24, 23, 22, 21, 5},
            {12, 13, 14, 15, 16},
            {11, 17, 18, 19, 20},
            {10, 9, 8, 7, 6}
    };
    assert(swimInWater(test) == 16);

    cout << "swimInWater completed!" << endl;
}
