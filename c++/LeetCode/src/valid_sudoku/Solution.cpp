//
// Created by Фарид Абдугалыев on 03.01.2022.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

bool valid_sudoku::Solution::isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        unordered_map<char, bool> used;
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '.') continue;

            if (used.count(board[i][j]) > 0) {
                return false;
            } else {
                used[board[i][j]] = true;
            }
        }
    }

    for (int i = 0; i < board.size(); i++) {
        unordered_map<char, bool> used;
        for (int j = 0; j < board[i].size(); j++) {
            if (board[j][i] == '.') continue;

            if (used.count(board[j][i]) > 0) {
                return false;
            } else {
                used[board[j][i]] = true;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            unordered_map<char, bool> used;

            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    int x = 3 * i + k;
                    int y = 3 * j + l;

                    if (board[x][y] == '.') continue;

                    if (used.count(board[x][y]) > 0) {
                        return false;
                    } else {
                        used[board[x][y]] = true;
                    }
                }
            }
        }
    }

    return true;
}

void valid_sudoku::Solution::test() {
    vector<vector<char>> test1 {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    assert(isValidSudoku(test1) == true);

    cout << "isValidSudoku completed!" << endl;
}
