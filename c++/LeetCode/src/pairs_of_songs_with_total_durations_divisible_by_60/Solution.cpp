//
// Created by dexhacker on 3/12/21.
//

#include "Solution.h"
#include <cassert>
#include <map>

int pairs_of_songs_with_total_durations_divisible_by_60::Solution::numPairsDivisibleBy60(vector<int> &time) {
    int answer = 0;
    map<int,vector<int>> hash_map;

    for (int i = 0; i < time.size(); i++) {
        int remainder = time[i] % 60;
        if (!hash_map[(60 - remainder) % 60].empty()) answer += hash_map[(60 - remainder) % 60].size();
        hash_map[remainder].push_back(i);
    }
    return answer;
}

void pairs_of_songs_with_total_durations_divisible_by_60::Solution::test() {
    vector<int> test1 {30, 20, 150, 100, 40};
    assert(numPairsDivisibleBy60(test1) == 3);

    vector<int> test2 {60,60,60};
    assert(numPairsDivisibleBy60(test2) == 3);

    cout << "numPairsDivisibleBy60 completed!" << endl;
}
