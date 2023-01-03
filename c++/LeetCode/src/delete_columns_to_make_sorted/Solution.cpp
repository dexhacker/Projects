//
// Created by dexhacker on 1/3/23.
//

#include "Solution.h"
#include <cassert>

int delete_columns_to_make_sorted::Solution::minDeletionSize(vector<string> &strs) {
    int answer = 0;
    for (int i = 0; i < strs[0].size(); i++) {
        int number = 0;
        for (int j = 0; j < strs.size(); j++) {
            if (number > strs[j][i] - 'a') {
                answer++;
                break;
            }

            number = strs[j][i] - 'a';
        }
    }
    return answer;
}

void delete_columns_to_make_sorted::Solution::test() {
    vector<string> strs {"cba", "daf", "ghi"};
    assert(minDeletionSize(strs) == 1);

    cout << "minDeletionSize completed!" << endl;
}
