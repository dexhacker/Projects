//
// Created by dexhacker on 10/13/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

vector<vector<string>> group_anagrams::Solution::groupAnagrams(vector<std::string> &strs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> answer;

    for (auto i : strs) {
        string sort_i = i;
        sort(sort_i.begin(), sort_i.end());
        m[sort_i].push_back(i);
    }

    for (auto p : m) answer.push_back(p.second);

    return answer;
}

void group_anagrams::Solution::test() {
    vector<string> test {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> answer {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}};
    auto result = groupAnagrams(test);

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            assert(answer[i][j] == result[i][j]);
        }
    }

    cout << "groupAnagrams completed!" << endl;
}
