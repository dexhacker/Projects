//
// Created by dexhacker on 1/27/23.
//

#include "Solution.h"
#include <cassert>

void concatenated_words::Solution::check(string s, int i, vector<string> &words) {
    if (s.size() < 2) return;

    if (i >= s.size()) {
        answer.push_back(s);
        return;
    }

    string sub_s;

    for (int j = i; j < s.size(); j++) {
        sub_s += s[j];
        if (m[sub_s] && s != sub_s) {
            words.push_back(sub_s);
            check(s, j + 1, words);
            words.pop_back();
        }
    }
}

vector<string> concatenated_words::Solution::findAllConcatenatedWordsInADict(vector<string> &words) {
    for (auto s : words) m[s] = true;
    vector<string> w;
    for (auto s : words) check(s, 0, w);

    sort( answer.begin(), answer.end() );
    answer.erase( unique( answer.begin(), answer.end() ), answer.end() );

    return answer;
}

void concatenated_words::Solution::test() {
    vector<string> words {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    vector<string> expected {"catsdogcats", "dogcatsdog", "ratcatdogcat"};
    auto result = findAllConcatenatedWordsInADict(words);
    for (int i = 0; i < expected.size(); i++) assert(expected[i] == result[i]);

    cout << "findAllConcatenatedWordsInADict completed!" << endl;
}
