//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <cassert>

long maximum_area_of_a_piece_of_cake_after_horizontal_and_vertical_cuts::Solution::max_long(long a, long b) {
    if (a > b) return a;
    return b;
}

int maximum_area_of_a_piece_of_cake_after_horizontal_and_vertical_cuts::Solution::maxArea(int h, int w,
                                                                                          vector<int> &horizontalCuts,
                                                                                          vector<int> &verticalCuts) {
    long h_max = 0, w_max = 0;
    int prev = 0;
    sort(horizontalCuts.begin(), horizontalCuts.end());
    for (auto i : horizontalCuts) {
        h_max = max_long(h_max, i - prev);
        prev = i;
    }
    h_max = max_long(h_max, h - prev);
    prev = 0;
    sort(verticalCuts.begin(), verticalCuts.end());
    for (auto i : verticalCuts) {
        w_max = max_long(w_max, i - prev);
        prev = i;
    }
    w_max = max_long(w_max, w - prev);
    return (h_max * w_max) % (long)(1e9 + 7);
}

void maximum_area_of_a_piece_of_cake_after_horizontal_and_vertical_cuts::Solution::test() {
    vector<int> test_h {3, 1};
    vector<int> test_v {1};
    assert(maxArea(5, 4, test_h, test_v) == 6);

    cout << "maxArea completed!" << endl;
}
