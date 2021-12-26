//
// Created by Фарид Абдугалыев on 26.12.2021.
//

#include "Solution.h"
#include <cmath>
#include <cassert>

vector<vector<int>> k_closest_points_to_origin::Solution::kClosest(vector<vector<int>> &points, int k) {
    vector<pair<int, int>> distances;

    for (int i = 0; i < points.size(); i++) {
        int distance = abs(points[i][0]) * abs(points[i][0]) + abs(points[i][1]) * abs(points[i][1]);
        distances.push_back({distance, i});
    }

    sort(distances.begin(), distances.end());

    vector<vector<int>> answer;

    for (int i = 0; i < min((int)distances.size(), k); i++) {
        int index = distances[i].second;
        answer.push_back(points[index]);
    }

    return answer;
}

void k_closest_points_to_origin::Solution::test() {
    vector<vector<int>> test1 {{1, 3}, {-2, 2}};
    vector<vector<int>> answer1 {{-2, 2}};
    assert(kClosest(test1, 1) == answer1);

    vector<vector<int>> test2 {{3, 3}, {5, -1}, {-2, 4}};
    vector<vector<int>> answer2 {{3, 3}, {-2, 4}};
    assert(kClosest(test2, 2) == answer2);

    cout << "kClosest completed!" << endl;
}
