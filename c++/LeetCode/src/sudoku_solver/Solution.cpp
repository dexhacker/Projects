//
// Created by dexhacker on 9/14/22.
//

#include "Solution.h"
#include <cassert>

bool sudoku_solver::Solution::check(vector<vector<char>> &board, int i, int j, char val) {
    int row = i - i%3, column = j - j%3;
    for(int x = 0; x < 9; x++) if(board[x][j] == val) return false;
    for(int y = 0; y < 9; y++) if(board[i][y] == val) return false;
    for(int x = 0; x < 3; x++)
        for(int y = 0; y < 3; y++)
            if(board[row + x][column + y] == val) return false;
    return true;
}

bool sudoku_solver::Solution::solveSudoku(vector<vector<char>> &board, int i, int j) {
    if(i == 9) return true;
    if(j == 9) return solveSudoku(board, i+1, 0);
    if(board[i][j] != '.') return solveSudoku(board, i, j+1);

    for(char c = '1'; c <= '9'; c++) {
        if(check(board, i, j, c)) {
            board[i][j] = c;
            if(solveSudoku(board, i, j + 1)) return true;
            board[i][j] = '.';
        }
    }

    return false;
}

void sudoku_solver::Solution::solveSudoku(vector<vector<char>> &board) {
    solveSudoku(board, 0, 0);
}

void sudoku_solver::Solution::test() {
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

    vector<vector<char>> answer1 {
            {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
            {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
            {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
            {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
            {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
            {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
            {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };

    solveSudoku(test1);
    assert(test1 == answer1);

    cout << "solveSudoku completed!" << endl;
}
