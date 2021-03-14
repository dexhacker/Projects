//
// Created by dexhacker on 3/11/21.
//

#ifndef LEETCODE_GAME_OF_LIFE_H
#define LEETCODE_GAME_OF_LIFE_H

#include <iostream>
#include <vector>

using namespace std;

namespace game_of_life {
    class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board);
        void test();
    };
}


#endif //LEETCODE_GAME_OF_LIFE_H
