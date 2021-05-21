//
// Created by dexhacker on 5/20/21.
//

#include "Solution.h"
#include <cassert>

void combination_sum_iii::Solution::solve(vector<int> &seq, int pos) {
    if (pos == k) {
        int sum = 0;
        for (int i : seq) sum += i;
        if (sum == n) list.push_back(seq);
        return;
    }

    for (int value = 1; value < 10; value++) {
        if (used[value] == 1 or (!seq.empty() and value <= seq.back())) continue;

        seq.push_back(value);
        used[value] = 1;
        solve(seq, pos + 1);
        seq.pop_back();
        used[value] = 0;
    }
}

vector<vector<int>> combination_sum_iii::Solution::combinationSum3(int K, int N) {
    k = K, n = N, list = {}, used = vector(9, 0);
    vector<int> empty;
    solve(empty, 0);
    return list;
}

void combination_sum_iii::Solution::test() {
    vector<vector<int>> answer1 {{1, 2, 4}};
    assert(combinationSum3(3, 7) == answer1);

//    vector<vector<int>> answer2 {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
//    assert(combinationSum3(3, 9) == answer2);
//
//    vector<vector<int>> answer3 {};
//    assert(combinationSum3(4, 1) == answer3);
//
//    vector<vector<int>> answer4 {};
//    assert(combinationSum3(3, 2) == answer4);
//
//    vector<vector<int>> answer5 {{1, 2, 3, 4, 5, 6, 7, 8, 9}};
//    assert(combinationSum3(9, 45) == answer5);

    cout << "maxProfit completed!" << endl;
}
