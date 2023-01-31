//
// Created by dexhacker on 1/31/23.
//

#include "Solution.h"
#include <cstring>
#include <cassert>

bool best_team_with_no_conflicts::Solution::comporator(pair<int, int> i1, pair<int, int> i2) {
    if (i1.first == i2.first) return i1.second < i2.second;
    return i1.first < i2.first;
}

int best_team_with_no_conflicts::Solution::bestTeamScore(vector<int> &scores, vector<int> &ages) {
    vector<pair<int, int>> players;
    for (int i = 0; i < ages.size(); i++) players.push_back({ages[i], scores[i]});
    sort(players.begin(), players.end(), comporator);

    int dp[players.size() + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < players.size(); i++) {
        dp[i + 1] = players[i].second;
        for (int j = 0; j < i; j++) {
            if (players[i].first > players[j].first && players[j].second > players[i].second) continue;
            if (players[j].first > players[i].first && players[i].second > players[j].second) continue;
            dp[i + 1] = max(dp[i + 1], dp[j + 1] + players[i].second);
        }
    }

    int answer = 0;
    for (int i = 0; i < sizeof(dp) / sizeof(int); i++) answer = max(answer, dp[i]);
    return answer;
}

void best_team_with_no_conflicts::Solution::test() {
    vector<int> scores {1, 3, 5, 10, 15};
    vector<int> ages {1, 2, 3, 4, 5};
    assert(bestTeamScore(scores, ages) == 34);

    cout << "bestTeamScore completed!" << endl;
}
