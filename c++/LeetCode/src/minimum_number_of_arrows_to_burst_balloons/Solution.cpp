//
// Created by Фарид Абдугалыев on 13.01.2022.
//

#include "Solution.h"
#include <cassert>

int minimum_number_of_arrows_to_burst_balloons::Solution::findMinArrowShots(vector<vector<int>> &points) {
    vector<pair<int, int>> pairs;
    for (auto i : points) pairs.push_back({i[0], i[1]});

    sort(pairs.begin(), pairs.end());

    int answer = 1;
    pair<int, int> p = pairs[0];
    for (int i = 1; i < pairs.size(); i++) {
        if (p.second < pairs[i].first) {
            answer++;
            p = pairs[i];
        } else if (p.second > pairs[i].second) {
            p = pairs[i];
        }
    }

    return answer;
}

void minimum_number_of_arrows_to_burst_balloons::Solution::test() {
    vector<vector<int>> test1 {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    assert(findMinArrowShots(test1) == 2);

    vector<vector<int>> test2 {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    assert(findMinArrowShots(test2) == 4);

    vector<vector<int>> test3 {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    assert(findMinArrowShots(test3) == 2);

    cout << "findMinArrowShots completed!" << endl;
}
