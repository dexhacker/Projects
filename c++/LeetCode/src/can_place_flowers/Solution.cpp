//
// Created by dexhacker on 5/21/21.
//

#include "Solution.h"
#include <cassert>

bool can_place_flowers::Solution::canPlaceFlowers(vector<int> &flowerbed, int n) {
    int count = 0;
    for (int i = 0; i < flowerbed.size(); i++) {
        if (flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == flowerbed.size() - 1 or flowerbed[i + 1] == 0)) {
            count++;
            flowerbed[i] = 1;
        }
    }
    return count >= n;
}

void can_place_flowers::Solution::test() {
    vector<int> test1 {1, 0, 0, 0, 1};
    assert(canPlaceFlowers(test1, 1) == true);

    vector<int> test2 {1, 0, 0, 0, 1};
    assert(canPlaceFlowers(test2, 2) == false);

    cout << "canPlaceFlowers completed!" << endl;
}
