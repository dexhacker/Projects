//
// Created by dexhacker on 11/28/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

vector<vector<int>> find_players_with_zero_or_one_losses::Solution::findWinners(vector<vector<int>> &matches) {
    unordered_map<int, int> m;
    for (auto match : matches) {
        m[match[1]]++;
        if (m.count(match[0]) == 0) m[match[0]] = 0;
    }

    vector<vector<int>> answer;
    vector<int> answer0;
    vector<int> answer1;

    for (auto p : m) {
        if (p.second == 0) answer0.push_back(p.first);
        if (p.second == 1) answer1.push_back(p.first);
    }

    sort(answer0.begin(), answer0.end());
    sort(answer1.begin(), answer1.end());

    answer.push_back(answer0);
    answer.push_back(answer1);

    return answer;
}

void find_players_with_zero_or_one_losses::Solution::test() {
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    vector<vector<int>> answer = {{1, 2, 10}, {4, 5, 7, 8}};
    auto result = findWinners(matches);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            assert(result[i][j] == answer[i][j]);
        }
    }

    cout << "findWinners completed!" << endl;
}
