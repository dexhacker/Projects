//
// Created by dexhacker on 5/22/21.
//

#include "Solution.h"
#include <cassert>

vector<vector<int>> pascals_triangle::Solution::generate(int numRows) {
    vector<vector<int>> answer;
    for (int i = 0; i < numRows; i++) {
        vector<int> row;
        if (!answer.empty()) {
            row.push_back(1);
            for (int j = 1; j < answer.back().size(); j++) {
                row.push_back(answer.back()[j - 1] + answer.back()[j]);
            }
        }
        row.push_back(1);
        answer.push_back(row);
    }
    return answer;
}

void pascals_triangle::Solution::test() {
    vector<vector<int>> test1 {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    assert(generate(5) == test1);

    vector<vector<int>> test2 {{1}};
    assert(generate(1) == test2);

    cout << "generate completed!" << endl;
}
