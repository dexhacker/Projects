//
// Created by dexhacker on 5/24/21.
//

#include "Solution.h"
#include <cassert>

int find_the_town_judge::Solution::findJudge(int n, vector<vector<int>> &trust) {
    vector<int> p(n + 1, 0), t(n + 1, 0);
    for (auto & pair : trust) {
        p[pair[0]]++;
        t[pair[1]]++;
    }

    for (int i = 1; i < p.size(); i++) if (t[i] == n - 1 and p[i] == 0) return i;
    return -1;
}

void find_the_town_judge::Solution::test() {
    vector<vector<int>> test1 {{1, 2}};
    assert(findJudge(2, test1) == 2);

    vector<vector<int>> test2 {{1, 3}, {2, 3}};
    assert(findJudge(3, test2) == 3);

    vector<vector<int>> test3 {{1, 3}, {2, 3}, {3, 1}};
    assert(findJudge(3, test3) == -1);

    vector<vector<int>> test4 {{1, 2}, {2, 3}};
    assert(findJudge(3, test4) == -1);

    vector<vector<int>> test5 {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    assert(findJudge(4, test5) == 3);

    cout << "findJudge completed!" << endl;
}
