//
// Created by dexhacker on 10/19/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

vector<string> top_k_frequent_words::Solution::topKFrequent(vector<std::string> &words, int k) {
    vector<string> answer;

    unordered_map<string, int> m;
    for (auto i : words) m[i]++;

    unordered_map<int, vector<string>> count_m;
    for (auto p : m) count_m[p.second].push_back(p.first);

    vector<pair<int, vector<string>>> v;

    for (auto p : count_m) v.push_back(p);
    sort(v.begin(), v.end());

    int index = v.size() - 1;
    while (k > 0) {
        auto w = v[index].second;
        sort(w.begin(), w.end());
        for (auto i : w) {
            answer.push_back(i);
            k--;
            if (k <= 0) break;
        }
        index--;
    }

    return answer;
}

void top_k_frequent_words::Solution::test() {
    vector<string> test {"i", "love", "leetcode", "i", "love", "coding"};
    auto result = topKFrequent(test, 2);
    vector<string> answer {"i", "love"};
    for (int i = 0; i < answer.size(); i++) {
        assert(answer[i] == result[i]);
    }

    cout << "topKFrequentWords completed!" << endl;
}
