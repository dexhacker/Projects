//
// Created by dexhacker on 9/18/22.
//

#include "Solution.h"
#include <cassert>

int maximum_matching_of_players_with_trainers::Solution::matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int r1 = players.size() - 1;
    int r2 = trainers.size() - 1;

    int result = 0;
    while (r1 >= 0 && r2 >= 0) {
        if (trainers[r2] >= players[r1]) {
            result++;
            r1--;
            r2--;
            continue;
        }

        r1--;
    }
    return result;
}

void maximum_matching_of_players_with_trainers::Solution::test() {
    vector<int> test11 {4, 7, 9};
    vector<int> test12 {8, 2, 5, 8};
    assert(matchPlayersAndTrainers(test11, test12) == 2);

    vector<int> test21 {1, 1, 1};
    vector<int> test22 {10};
    assert(matchPlayersAndTrainers(test21, test22) == 1);

    cout << "matchPlayersAndTrainers completed!" << endl;
}
