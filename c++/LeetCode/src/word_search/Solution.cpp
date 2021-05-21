//
// Created by dexhacker on 4/29/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>

bool sub_exist(vector<vector<char>> &board, string word, unordered_map<int, unordered_map<int, int>> hash, int count, int i, int j) {
    hash[i][j] = 1;
    if (count < 0) return true;

    if (i - 1 >= 0 && hash[i - 1][j] == 0 && board[i - 1][j] == word[count]) {
        if (sub_exist(board, word, hash, count - 1, i - 1, j)) return true;
    }
    if (j - 1 >= 0 && hash[i][j - 1] == 0 && board[i][j - 1] == word[count]) {
        if (sub_exist(board, word, hash, count - 1, i, j - 1)) return true;
    }
    if (i + 1 < board.size() && hash[i + 1][j] == 0 && board[i + 1][j] == word[count]) {
        if (sub_exist(board, word, hash, count - 1, i + 1, j)) return true;
    }
    if (j + 1 < board[0].size() && hash[i][j + 1] == 0 && board[i][j + 1] == word[count]) {
        if (sub_exist(board, word, hash, count - 1, i, j + 1)) return true;
    }
    return false;
}

bool word_search::Solution::exist(vector<vector<char>> &board, string word) {
    unordered_map<int, unordered_map<int, int>> hash;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[word.size() - 1]) {
                if (sub_exist(board, word, hash, word.size() - 2, i, j)) return true;
            }
        }
    }

    return false;
}

void word_search::Solution::test() {
    vector<vector<char>> test1 {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    assert(exist(test1, "ABCCED") == true);

    vector<vector<char>> test2 {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    assert(exist(test2, "SEE") == true);

    vector<vector<char>> test3 {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    assert(exist(test3, "ABCB") == false);

    vector<vector<char>> test4 {{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
    assert(exist(test4, "AAB") == true);

    cout << "exist completed!" << endl;
}
