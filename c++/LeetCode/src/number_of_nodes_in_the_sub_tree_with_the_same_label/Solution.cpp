//
// Created by dexhacker on 1/12/23.
//

#include "Solution.h"
#include <cassert>

vector<int>
number_of_nodes_in_the_sub_tree_with_the_same_label::Solution::dfs(vector<vector<int>> &adj, string &labels, int i,
                                                                   vector<int> &result) {
    vector<int> ans(26, 0);
    result[i] = 1;
    ans[labels[i] - 'a'] = 1;

    for (int j = 0; j != adj[i].size(); j++) {
        if (!result[adj[i][j]]) {
            vector<int> tmp = dfs(adj, labels, adj[i][j], result);
            for(int k = 0; k != 26; k++) ans[k] += tmp[k];
        }
    }

    result[i] = ans[labels[i] - 'a'];

    return ans;
}

vector<int>
number_of_nodes_in_the_sub_tree_with_the_same_label::Solution::countSubTrees(int n, vector<vector<int>> &edges,
                                                                             string labels) {
    vector<vector<int>> adj(n);
    vector<int> result(n ,0);
    for(int i = 0; i != edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    dfs(adj, labels, 0, result);
    return result;
}

void number_of_nodes_in_the_sub_tree_with_the_same_label::Solution::test() {
    vector<vector<int>> edges {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    vector<int> answer {2, 1, 1, 1, 1, 1, 1};
    auto result = countSubTrees(7, edges, "abaedcd");
    assert(answer.size() == result.size());
    for (int i = 0; i < answer.size(); i++) assert(answer[i] == result[i]);
    cout << "countSubTrees completed!" << endl;
}
