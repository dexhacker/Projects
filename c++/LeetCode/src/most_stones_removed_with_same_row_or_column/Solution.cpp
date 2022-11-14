//
// Created by dexhacker on 11/14/22.
//

#include "Solution.h"
#include <cassert>

void most_stones_removed_with_same_row_or_column::Solution::dfs(vector<vector<int>> &stones, int index, vector<bool> &visited) {
    visited[index] = true;

    for(int i = 0; i<n; i++) {
        if(!visited[i] && ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
            dfs(stones, i, visited);
        }
    }
}

int most_stones_removed_with_same_row_or_column::Solution::removeStones(vector<vector<int>> &stones) {
    n = stones.size();
    vector<bool> visited(n, false);

    int count = 0;
    for(int i = 0; i<n; i++) {
        if(visited[i]) continue;
        dfs(stones, i, visited);
        count++;
    }

    return n - count;
}

void most_stones_removed_with_same_row_or_column::Solution::test() {
    vector<vector<int>> test {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    assert(removeStones(test) == 5);

    cout << "removeStones completed!" << endl;
}
