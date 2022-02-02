//
// Created by Фарид Абдугалыев on 02.02.2022.
//

#include "Solution.h"
#include <cassert>

bool find_all_anagrams_in_a_string::Solution::equal(vector<int> &current, vector<int> &target) {
    for (int i = 0; i < current.size(); i++) {
        if (current[i] != target[i]) return false;
    }

    return true;
}

vector<int> find_all_anagrams_in_a_string::Solution::findAnagrams(string s, string p) {
    if (s.size() < p.size()) return {};

    vector<int> targetAnagram(26, 0);
    vector<int> currentAnagram(26, 0);
    vector<int> answer;

    for (int i = 0; i < p.size(); i++) {
        targetAnagram[p[i] - 'a']++;
    }

    for (int i = 0; i < p.size(); i++) {
        currentAnagram[s[i] - 'a']++;
    }

    if (equal(currentAnagram, targetAnagram)) answer.push_back(0);

    for (int i = p.size(); i < s.size(); i++) {
        currentAnagram[s[i] - 'a']++;
        currentAnagram[s[i - p.size()] - 'a']--;
        if (equal(currentAnagram, targetAnagram)) answer.push_back(i - p.size() + 1);
    }

    return answer;
}

void find_all_anagrams_in_a_string::Solution::test() {
    vector<int> answer1 {0, 6};
    assert(findAnagrams("cbaebabacd", "abc") == answer1);

    vector<int> answer2 {0, 1, 2};
    assert(findAnagrams("abab", "ab") == answer2);

    cout << "findAnagrams completed!" << endl;
}
