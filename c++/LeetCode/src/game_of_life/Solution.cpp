//
// Created by dexhacker on 3/11/21.
//

#include "Solution.h"
#include <cassert>

int live_count(vector<vector<int>> &board, int i, int j) {
    int count = 0;

    int x_start = i - 1, x_finish = i + 1, y_start = j - 1, y_finish = j + 1;
    if (x_start < 0) x_start = i;
    if (y_start < 0) y_start = j;
    if (x_finish > board.size() - 1) x_finish = i;
    if (y_finish > board[i].size() - 1) y_finish = j;
    for (int x = x_start; x <= x_finish; x++) {
        for (int y = y_start; y <= y_finish; y++) {
            if (x == i && y == j) continue;
            if (board[x][y] % 2 == 1) count++;
        }
    }
    return count;
}

void game_of_life::Solution::gameOfLife(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] % 2 == 0) {
                if (live_count(board, i, j) == 3)
                    board[i][j] += 2;
            } else {
                int live = live_count(board, i, j);
                if (live == 2 || live == 3)
                    board[i][j] += 2;
            }
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            board[i][j] = (board[i][j] > 1) ? 1 : 0;
        }
    }
}

void game_of_life::Solution::test() {
    vector<vector<int>> test1 {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    gameOfLife(test1);
    vector<vector<int>> answer1 = {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};
    assert(test1 == answer1);

    vector<vector<int>> test2 {{1, 1}, {1, 0}};
    gameOfLife(test2);
    vector<vector<int>> answer2 = {{1, 1}, {1, 1}};
    assert(test2 == answer2);

    vector<vector<int>> test3 {{0, 0}};
    gameOfLife(test3);
    vector<vector<int>> answer3 = {{0, 0}};
    assert(test3 == answer3);

    cout << "gameOfLife completed!" << endl;
}
