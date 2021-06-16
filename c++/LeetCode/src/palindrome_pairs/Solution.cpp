//
// Created by dexhacker on 6/14/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

bool palindrome_pairs::Solution::is_palindrome(string &s, int start, int end) {
    while(start < end) {
        if(s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

vector<vector<int>> palindrome_pairs::Solution::palindromePairs(vector<string> &words) {
    vector<vector<int>> result;
    unordered_map<string, int> dict;
    for(int i = 0; i < words.size(); i++) {
        dict[words[i]] = i;
    }
    for(int i = 0; i < words.size(); i++) {
        for(int j = 0; j <= words[i].length(); j++) {
            if(is_palindrome(words[i], j, words[i].size() - 1)) {
                string suffix = words[i].substr(0, j);
                reverse(suffix.begin(), suffix.end());
                if(dict.find(suffix) != dict.end() && i != dict[suffix]) {
                    result.push_back({i, dict[suffix]});
                }
            }

            if(j > 0 && is_palindrome(words[i], 0, j - 1)) {
                string prefix = words[i].substr(j);
                reverse(prefix.begin(), prefix.end());
                if(dict.find(prefix) != dict.end() && dict[prefix] != i) {
                    result.push_back({dict[prefix], i});
                }
            }
        }
    }
    return result;
}

void palindrome_pairs::Solution::test() {
    vector<string> test {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> answer {{0, 1}, {1, 0}, {3, 2}, {2, 4}};
    assert(palindromePairs(test) == answer);

    cout << "palindromePairs completed!" << endl;
}
