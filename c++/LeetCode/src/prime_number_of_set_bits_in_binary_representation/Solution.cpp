//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

int prime_number_of_set_bits_in_binary_representation::Solution::countPrimeSetBits(int left, int right) {
    unordered_map<int, bool> hm {
            {2, true},
            {3, true},
            {5, true},
            {7, true},
            {11, true},
            {13, true},
            {17, true},
            {19, true}
    };
    int count = 0;
    for (int i = left; i <= right; i++) {
        int ones = 0;
        for (int j = 0; j <= 20; j++) {
            if (i & 1 << j) ones++;
        }
        if (hm[ones]) count++;
    }
    return count;
}

void prime_number_of_set_bits_in_binary_representation::Solution::test() {
    assert(countPrimeSetBits(842, 888) == 23);

    cout << "countPrimeSetBits completed!" << endl;
}
