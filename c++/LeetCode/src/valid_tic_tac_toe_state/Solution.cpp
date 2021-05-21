//
// Created by dexhacker on 5/1/21.
//

#include "Solution.h"
#include <cassert>

bool is_win(vector<string> &board, char c) {
    return ((board[0][0] == c && board[0][1] == c && board[0][2] == c) ||
            (board[1][0] == c && board[1][1] == c && board[1][2] == c) ||
            (board[2][0] == c && board[2][1] == c && board[2][2] == c) ||
            (board[0][0] == c && board[1][0] == c && board[2][0] == c) ||
            (board[0][1] == c && board[1][1] == c && board[2][1] == c) ||
            (board[0][2] == c && board[1][2] == c && board[2][2] == c) ||
            (board[0][0] == c && board[1][1] == c && board[2][2] == c) ||
            (board[0][2] == c && board[1][1] == c && board[2][0] == c));
}

bool valid_tic_tac_toe_state::Solution::validTicTacToe(vector<string> &board) {
    int x_count = 0, o_count = 0;
    for(string s: board) {
        for(char c: s) {
            if(c == 'X') x_count++;
            else if(c == 'O') o_count++;
        }
    }
    if(x_count != o_count && x_count != o_count + 1) return false;
    if(is_win(board, 'X') && x_count != o_count + 1) return false;
    if(is_win(board, 'O') && x_count != o_count) return false;
    return true;
}

void valid_tic_tac_toe_state::Solution::test() {
    vector<string> test1 {"O  ", "   ", "   "};
    assert(validTicTacToe(test1) == false);

    vector<string> test2 {"XOX", " X ", "   "};
    assert(validTicTacToe(test2) == false);

    vector<string> test3 {"XXX", "   ", "OOO"};
    assert(validTicTacToe(test3) == false);

    vector<string> test4 {"XOX", "O O", "XOX"};
    assert(validTicTacToe(test4) == true);

    cout << "validTicTacToe completed!" << endl;
}
