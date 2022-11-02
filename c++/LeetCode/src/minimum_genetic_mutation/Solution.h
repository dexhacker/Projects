//
// Created by dexhacker on 11/2/22.
//

#ifndef LEETCODE_MINIMUM_GENETIC_MUTATION_H
#define LEETCODE_MINIMUM_GENETIC_MUTATION_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace minimum_genetic_mutation {
    class Solution {
    public:
        void dfs(string start, string end, int count);
        int minMutation(string start, string end, vector<string>& bank);
        void test();

    private:
        unordered_map<string, bool> used;
        int answer = 9;
        vector<char> letters {'A', 'C', 'G', 'T'};
    };
}

#endif //LEETCODE_MINIMUM_GENETIC_MUTATION_H
