//
// Created by dexhacker on 11/17/22.
//

#include "Solution.h"
#include <vector>
#include <stack>
#include <cassert>

string permutation_sequence::Solution::getPermutation(int n, int k) {
    vector<char> numbers {'0'};
    stack<int> factorials;
    factorials.push(1);
    for (int i = 1; i <= n; i++) {
        numbers.push_back('0' + i);
        factorials.push(factorials.top() * i);
    }
    string answer;
    factorials.pop();
    for (int i = 1; i <= n; i++) {
        int del = k / factorials.top();
        if (k % factorials.top() > 0) del++;
        answer += numbers[del];
        vector<char> new_numbers;
        for (int j = 0; j < numbers.size(); j++) if (j != del) new_numbers.push_back(numbers[j]);

        numbers = new_numbers;
        k = k % factorials.top();
        if (k == 0) k = factorials.top();
        factorials.pop();
    }

    return answer;
}

void permutation_sequence::Solution::test() {
    assert(getPermutation(4, 9) == "2314");

    cout << "getPermutation completed!" << endl;
}
