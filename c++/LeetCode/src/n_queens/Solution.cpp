//
// Created by dexhacker on 5/1/21.
//

#include "Solution.h"
#include <cassert>

bool n_queens::Solution::is_valid_placing(vector<int> &current_seq) {
    for (int i = 0; i < current_seq.size(); i++)
        for (int j = i + 1; j < current_seq.size(); j++)
            if (abs(j - i) == abs(current_seq[j] - current_seq[i]))
                return false;
    return true;
}

void n_queens::Solution::solve(vector<int> &current_seq, int current_position) {
    if (current_position == n) {
        list.push_back(current_seq);
        return;
    }

    for (int next_number = 0; next_number < n; next_number++) {
        if (used[next_number] == 1) continue;

        used[next_number] = 1;
        current_seq.push_back(next_number);
        if (is_valid_placing(current_seq)) solve(current_seq, current_position + 1);
        current_seq.pop_back();
        used[next_number] = 0;
    }
}

vector<vector<string>> n_queens::Solution::solveNQueens(int board_size) {
    n = board_size, used = {}, list = {};
    used.reserve(n);
    vector<int> empty;
    solve(empty, 0);
    vector<vector<string>> list_of_tables;
    for (auto & seq : list) {
        vector<string> table(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                table[i] = table[i] + ".";
        for (int i = 0; i < n; i++) table[seq[i]][i] = 'Q';
        list_of_tables.push_back(table);
    }
    return list_of_tables;
}

void n_queens::Solution::test() {
    vector<vector<string>> answer1 {{"..Q.", "Q...", "...Q", ".Q.."}, {".Q..", "...Q", "Q...", "..Q."}};
    assert(solveNQueens(4) == answer1);

    vector<vector<string>> answer2 {{"Q"}};
    assert(solveNQueens(1) == answer2);

    cout << "solveNQueens completed!" << endl;
}
