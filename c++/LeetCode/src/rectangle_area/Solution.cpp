//
// Created by dexhacker on 11/17/22.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int rectangle_area::Solution::computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    vector<int> axs {ax1, ax2};
    vector<int> ays {ay1, ay2};
    vector<int> bxs {bx1, bx2};
    vector<int> bys {by1, by2};
    sort(axs.begin(), axs.end());
    sort(ays.begin(), ays.end());
    sort(bxs.begin(), bxs.end());
    sort(bys.begin(), bys.end());

    vector<pair<int, int>> xs {{axs[0], axs[1]}, {bxs[0], bxs[1]}};
    vector<pair<int, int>> ys {{ays[0], ays[1]}, {bys[0], bys[1]}};
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    int covered_area = 0;
    if (xs[0].second > xs[1].first && ys[0].second > ys[1].first) {
        covered_area = (xs[1].first - min(xs[0].second, xs[1].second)) * (ys[1].first - min(ys[0].second, ys[1].second));
    }

    int covered_a = (axs[1] - axs[0]) * (ays[1] - ays[0]);
    int covered_y = (bxs[1] - bxs[0]) * (bys[1] - bys[0]);

    return covered_a + covered_y - covered_area;
}

void rectangle_area::Solution::test() {
    assert(computeArea(-3,0, 3, 4, 0, -1, 9, 2) == 45);

    cout << "computeArea completed!" << endl;
}
