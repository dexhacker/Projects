//
// Created by dexhacker on 7/25/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

vector<vector<string>> word_ladder_ii::Solution::findLadders(string beginWord, string endWord,
                                                             vector<string> &wordList) {
    unordered_map<string, bool> used;
    for (int i = 0; i < wordList.size(); ++i) used[wordList[i]] = false;

    if (used.count(endWord) == 0) return {};
    if (used.count(beginWord) == 0) wordList.push_back(beginWord);

    unordered_map<string, vector<string>> word_map;
    for (int i = 0; i < wordList.size(); ++i) {
        string str = wordList[i];
        for (int j = 0; j < beginWord.size(); ++j) {
            char letter = str[j];
            for (int k = 0; k < 26; ++k) {
                str[j] = 'a' + k;
                if (used.count(str) > 0 and wordList[i] != str) {
                    word_map[wordList[i]].push_back(str);
                }
            }
            str[j] = letter;
        }
    }

    vector<WordParent*> q;
    auto first_wp = new WordParent(nullptr, beginWord);
    q.push_back(first_wp);
    used[beginWord] = true;
    bool isFinished = false;
    vector<WordParent*> answersWP;
    while (!isFinished and !q.empty()) {
        vector<WordParent*> new_q;
        for (auto wp : q) {
            used[wp->word] = true;
            for (auto nextWord : word_map[wp->word]) {
                if (used[nextWord]) continue;

                auto new_wp = new WordParent(wp, nextWord);
                if (nextWord == endWord) {
                    answersWP.push_back(new_wp);
                    isFinished = true;
                } else {
                    new_q.push_back(new_wp);
                }
            }
        }
        q = new_q;
    }

    vector<vector<string>> answer;
    for (auto wp : answersWP) {
        vector<string> path;
        while(wp) {
            path.push_back(wp->word);
            wp = wp->parent;
        }
        reverse(path.begin(), path.end());
        answer.push_back(path);
    }
    return answer;
}

void word_ladder_ii::Solution::test() {
    vector<string> test {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> answer {
            {"hit", "hot", "dot", "dog", "cog"},
            {"hit", "hot", "lot", "log", "cog"}
    };
    assert(findLadders("hit", "cog", test) == answer);

    cout << "findLadders completed!" << endl;
}
