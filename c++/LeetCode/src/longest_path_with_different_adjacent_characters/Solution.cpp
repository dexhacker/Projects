//
// Created by dexhacker on 1/13/23.
//

#include "Solution.h"
#include <cassert>

int longest_path_with_different_adjacent_characters::Solution::dfs(string &s, int curr_node) {
    if (child[curr_node].empty()) return 1;
    int mx1 = 0, mx2 = 0;
    for (auto &child_node : child[curr_node]) {
        int len = dfs(s, child_node);
        ans = max(ans, len);
        if (s[curr_node] == s[child_node]) continue;
        if (len > mx1) {
            mx2 = mx1;
            mx1 = len;
        } else {
            mx2 = max(mx2, len);
        }
    }
    ans = max(ans, 1 + mx1 + mx2);
    return 1 + mx1;
}

int longest_path_with_different_adjacent_characters::Solution::longestPath(vector<int> &parent, string s) {
    int n = parent.size();
    for(int i = 1; i < n; i++) child[parent[i]].push_back(i);
    dfs(s, 0);
    return ans;
}

void longest_path_with_different_adjacent_characters::Solution::test() {
    vector<int> parent {-1, 0, 0, 1, 1, 2};
    assert(longestPath(parent, "abacbe") == 3);

    cout << "longestPath completed!" << endl;
}
