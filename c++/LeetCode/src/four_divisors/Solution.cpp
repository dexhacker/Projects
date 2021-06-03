//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <cassert>

vector<int> four_divisors::Solution::find_divisors(int number) {
    vector<int> divisors;
    for (int i = 1; i * i <= number; i++) {
        if (number % i == 0) {
            divisors.push_back(i);
            if (number / i != i) divisors.push_back(number / i);
        }
    }
    return divisors;
}

int four_divisors::Solution::sumFourDivisors(vector<int> &nums) {
    int sum = 0;
    for (auto number : nums) {
        auto divisors = find_divisors(number);
        if (divisors.size() == 4) {
            for (auto divisor : divisors) sum += divisor;
        }
    }
    return sum;
}

void four_divisors::Solution::test() {
    vector<int> test {21, 4, 7};
    assert(sumFourDivisors(test) == 32);

    cout << "sumFourDivisors completed!" << endl;
}
