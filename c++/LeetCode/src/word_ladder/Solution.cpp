//
// Created by dexhacker on 3/28/21.
//

#include "Solution.h"
#include <cassert>
#include <queue>

int word_ladder::Solution::ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    queue<pair<string, int>> words_queue;
    words_queue.push(make_pair(beginWord, 1));
    while (!words_queue.empty()) {
        auto current_pair = words_queue.front();
        int i = 0;
        while (i < wordList.size()) {
            string current_word = current_pair.first;
            int different_letter = 0;
            for (int j = 0; j < current_word.size(); j++) {
                if (wordList[i][j] != current_word[j]) different_letter++;
                if (different_letter > 1) break;
            }
            if (different_letter < 2) {
                if (wordList[i] == endWord) return current_pair.second + 1;
                string temp = wordList[wordList.size() - 1];
                words_queue.push(make_pair(wordList[i], current_pair.second + 1));
                wordList[wordList.size() - 1] = wordList[i];
                wordList[i] = temp;
                wordList.pop_back();
            } else {
                i++;
            }
        }
        words_queue.pop();
    }
    return 0;
}

void word_ladder::Solution::test() {
    vector<string> test1 {"hot", "dot", "dog", "lot", "log", "cog"};
    assert(ladderLength("hit", "cog", test1) == 5);

    vector<string> test2 {"hot", "dot", "dog", "lot", "log"};
    assert(ladderLength("hit", "cog", test2) == 0);

    cout << "ladderLength completed!" << endl;
}
