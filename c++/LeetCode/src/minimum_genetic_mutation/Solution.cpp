//
// Created by dexhacker on 11/2/22.
//

#include "Solution.h"
#include <cassert>

void minimum_genetic_mutation::Solution::dfs(string start, string end, int count) {
    for (int i = 0; i < start.size(); i++) {
        char tmp = start[i];

        for (auto c : letters) {
            start[i] = c;
            if (used.count(start) > 0 && !used[start]) {
                if (start == end) {
                    answer = min(answer, count + 1);
                    start[i] = tmp;
                    break;
                }
                used[start] = true;
                dfs(start, end, count + 1);
                used[start] = false;
            }
        }
        start[i] = tmp;
    }
}

int minimum_genetic_mutation::Solution::minMutation(string start, string end, vector<string> &bank) {
    for (auto b : bank) used[b] = false;

    dfs(start, end, 0);

    return (answer == 9) ? -1 : answer;
}

void minimum_genetic_mutation::Solution::test() {
    vector<string> test {"AACCGGTA","AACCGCTA","AAACGGTA"};

    assert(minMutation("AACCGGTT", "AAACGGTA", test) == 2);

    cout << "minMutation completed!" << endl;
}
