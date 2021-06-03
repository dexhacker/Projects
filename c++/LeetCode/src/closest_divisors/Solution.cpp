//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <cmath>
#include <cassert>

pair<int, int> closest_divisors::Solution::find_divisor(int num) {
    for (int i = (int)sqrt(num); i > 0; i--) if (num % i == 0) return {i, num / i};
    return {INT32_MIN, INT32_MAX};
}

vector<int> closest_divisors::Solution::closestDivisors(int num) {
    auto pair1 = find_divisor(num + 1);
    auto pair2 = find_divisor(num + 2);

    if (pair1.second - pair1.first <= pair2.second - pair2.first) return {pair1.first, pair1.second};

    return {pair2.first, pair2.second};
}

void closest_divisors::Solution::test() {
    vector<int> answer {3 ,3};
    assert(closestDivisors(8) == answer);

    cout << "closestDivisors completed!" << endl;
}
