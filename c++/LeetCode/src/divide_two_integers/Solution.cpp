//
// Created by Фарид Абдугалыев on 21.12.2021.
//

#include "Solution.h"
#include <cassert>

long divide_two_integers::Solution::positiveDivide(long answer, long dividend, long divisor) {
    if (dividend < divisor) return answer;

    long current_result = 1;
    long d = divisor;
    while ((d << 1) < dividend) {
        d = d << 1;
        current_result = current_result << 1;
    }

    answer += current_result;
    dividend -= d;
    return positiveDivide(answer, dividend, divisor);
}

int divide_two_integers::Solution::divide(int dividend, int divisor) {
    if (dividend == 0) return 0;

    long first = (long)dividend;
    long second = (long)divisor;
    bool positive = true;

    if (first < 0) {
        first = first - first - first;
        positive = !positive;
    }

    if (second < 0) {
        second = second - second - second;
        positive = !positive;
    }

    long answer = positiveDivide(0, first, second);


    if (!positive) {
        answer = answer - answer - answer;
    }

    if (answer > INT32_MAX) {
        return INT32_MAX;
    }

    if (answer < INT32_MIN) {
        return INT32_MIN;
    }

    return answer;
}

void divide_two_integers::Solution::test() {
    assert(divide(10, 3) == 3);
    assert(divide(7, -3) == -2);
    assert(divide(0, 1) == 0);
    assert(divide(1, 1) == 1);
    assert(divide(-2147483648, -1) == 2147483647);

    cout << "divide completed!" << endl;
}
