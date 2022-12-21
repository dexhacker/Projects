//
// Created by dexhacker on 12/21/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

bool possible_bipartition::Solution::possibleBipartition(int n, vector<vector<int>> &dislikes) {
    if (dislikes.empty()) return true;
    unordered_map<int, bool> a, b;
    a[dislikes[0][0]] = true;
    b[dislikes[0][1]] = true;
    while (!dislikes.empty()) {
        vector<vector<int>> new_dislikes;
        bool used = false;
        for (auto d : dislikes) {
            if (a[d[0]] && a[d[1]]) return false;
            if (b[d[0]] && b[d[1]]) return false;
            if (a[d[0]] && b[d[1]]) continue;
            if (a[d[1]] && b[d[0]]) continue;
            if (a[d[0]]) {
                b[d[1]] = true;
                used = true;
                continue;
            }
            if (a[d[1]]) {
                b[d[0]] = true;
                used = true;
                continue;
            }
            if (b[d[0]]) {
                a[d[1]] = true;
                used = true;
                continue;
            }
            if (b[d[1]]) {
                a[d[0]] = true;
                used = true;
                continue;
            }
            new_dislikes.push_back(d);
        }
        dislikes = new_dislikes;
        if (!used && !dislikes.empty()) {
            a[dislikes[0][0]] = true;
            b[dislikes[0][1]] = true;
        }
    }
    return true;
}

void possible_bipartition::Solution::test() {
    vector<vector<int>> dislikes {{1, 2}, {1, 3}, {2, 4}};
    assert(possibleBipartition(4, dislikes) == true);

    cout << "possibleBipartition completed!" << endl;
}
