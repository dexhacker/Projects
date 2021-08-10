//
// Created by dexhacker on 8/5/21.
//

#ifndef LEETCODE_STONE_GAME_H
#define LEETCODE_STONE_GAME_H

#include <iostream>
#include <vector>

using namespace std;

namespace stone_game {
    class Solution {
    public:
        void dfs(int l, int r, bool isAlex);
        bool stoneGame(vector<int>& piles);
        void test();

    private:
        vector<int> p;
        bool answer = false;
        int alex = 0;
        int lee = 0;
    };
}

#endif //LEETCODE_STONE_GAME_H
