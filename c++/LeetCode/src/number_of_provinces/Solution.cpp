//
// Created by dexhacker on 5/23/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int number_of_provinces::Solution::findCircleNum(vector<vector<int>> &isConnected) {
    vector<bool> used(isConnected.size(), false);
    int count = 0;
    for (int i = 0; i < isConnected.size(); i++) {
        if (!used[i]) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1 and !used[j]) {
                    count++;
                    queue<pair<int, int>> path;
                    used[j] = true;
                    path.push({i, j});
                    while (!path.empty()) {
                        auto current_pair = path.front();
                        path.pop();
                        for (int k = 0; k < isConnected[0].size(); k++) {
                            if (isConnected[current_pair.second][k] == 1 and !used[k]) {
                                used[k] = true;
                                path.push({current_pair.second, k});
                            }
                        }
                    }
                }
            }
        }
    }
    return count;
}

void number_of_provinces::Solution::test() {
    vector<vector<int>> test1 {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    assert(findCircleNum(test1) == 2);

    vector<vector<int>> test2 {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    assert(findCircleNum(test2) == 3);

    cout << "findCircleNum completed!" << endl;
}
