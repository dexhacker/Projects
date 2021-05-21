//
// Created by dexhacker on 4/30/21.
//

#include "Solution.h"
#include <cassert>

vector<int> counting_bits::Solution::countBits(int num) {
    vector<int> answer;
    for (int i = 0; i <= num; i++) {
        int current_num = i;
        int one_count = 0;
        while (current_num > 0) {
            one_count += current_num % 2;
            current_num /= 2;
        }
        answer.push_back(one_count);
    }
    return answer;
}

void counting_bits::Solution::test() {
    vector<int> answer1 {0, 1, 1};
    assert(countBits(2) == answer1);

    vector<int> answer2 {0, 1, 1, 2, 1, 2};
    assert(countBits(5) == answer2);

    cout << "countBits completed!" << endl;
}
