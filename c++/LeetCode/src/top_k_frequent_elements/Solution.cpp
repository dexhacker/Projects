//
// Created by dexhacker on 4/16/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>

vector<int> top_k_frequent_elements::Solution::topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> hash_map;
    vector<pair<int, int>> pairs;
    vector<int> answer;
    for (int i : nums) hash_map[i]++;

    for (auto const & [key, value] : hash_map) {
        pairs.emplace_back(value, key);
    }
    sort(pairs.begin(), pairs.end());
    for (int i = pairs.size() - k; i < pairs.size(); i++) {
        answer.push_back(pairs[i].second);
    }
    return answer;
}

void top_k_frequent_elements::Solution::test() {
    vector<int> test1 {1, 1, 1, 2, 2, 3};
    vector<int> answer1 {2, 1};
    assert(topKFrequent(test1, 2) == answer1);

    vector<int> test2 {1};
    vector<int> answer2 {1};
    assert(topKFrequent(test2, 1) == answer2);

    vector<int> test3 {1, 2};
    vector<int> answer3 {1, 2};
    assert(topKFrequent(test3, 2) == answer3);

    cout << "topKFrequent completed!" << endl;
}
