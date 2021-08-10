//
// Created by dexhacker on 8/5/21.
//

#include "Solution.h"
#include <cassert>

void stone_game::Solution::dfs(int l, int r, bool isAlex) {
    if (answer) return;
    if (r < l) {
        answer = alex > lee;
        return;
    }
    if (isAlex) {
        alex += p[l];
        dfs(l + 1, r, false);
        alex -= p[l];
        alex += p[r];
        dfs(l, r - 1, false);
        alex -= p[l];
    } else {
        lee += p[l];
        dfs(l + 1, r, true);
        lee -= p[l];
        lee += p[r];
        dfs(l, r - 1, true);
        lee -= p[l];
    }
}

bool stone_game::Solution::stoneGame(vector<int> &piles) {
    p = piles;
    dfs(0, p.size() - 1, true);
    return answer;
}

void stone_game::Solution::test() {
    vector<int> test {5, 3, 4, 5};
    assert(stoneGame(test) == true);

    cout << "stoneGame completed!" << endl;
}
