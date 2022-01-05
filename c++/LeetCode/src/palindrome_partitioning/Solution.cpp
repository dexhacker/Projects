//
// Created by Фарид Абдугалыев on 05.01.2022.
//

#include "Solution.h"
#include <cassert>

bool palindrome_partitioning::Solution::isPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }

    return true;
}

void palindrome_partitioning::Solution::dfs(int index, vector<string> sub_answer) {
    string current = "";
    if (index >= str.size()) {
        if (!sub_answer.empty()) {
            answer.push_back(sub_answer);
        }
    } else {
        for (int i = index; i < str.size(); i++) {
            vector<string> current_sub_answer(sub_answer);
            current += str[i];
            if (isPalindrome(current)) {
                current_sub_answer.push_back(current);
                dfs(i + 1, current_sub_answer);
            }
        }
    }
}

vector<vector<string>> palindrome_partitioning::Solution::partition(string s) {
    str = s;
    dfs(0, {});

    return answer;
}

void palindrome_partitioning::Solution::test() {
    vector<vector<string>> answer1 {{"a", "a", "b"}, {"aa", "b"}};
    assert(partition("aab") == answer1);

    cout << "partition completed!" << endl;
}
