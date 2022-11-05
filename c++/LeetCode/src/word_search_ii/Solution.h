//
// Created by dexhacker on 11/5/22.
//

#ifndef LEETCODE_WORD_SEARCH_II_H
#define LEETCODE_WORD_SEARCH_II_H

#include <iostream>
#include <vector>

using namespace std;

struct trieNode {
    bool endOfWord;
    trieNode* children[26];
    string word;
};

namespace word_search_ii {
    class Solution {
    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
        void test();

    private:
        vector<string> result;
        int r, c;
        vector<pair<int, int>> directions{{-1, 0},{1, 0},{0, 1},{0, -1}};
        trieNode* getNode();
        void insert(trieNode* root, string str);
        void DFS(vector<vector<char>>& board, int i, int j, trieNode* root);
    };
}

#endif //LEETCODE_WORD_SEARCH_II_H
