//
// Created by dexhacker on 9/22/22.
//

#include "Solution.h"
#include <cassert>

string reverse_words_in_a_string_iii::Solution::reverseWords(string s) {
    string answer = "";
    string word = "";
    for (auto i : s) {
        if (i == ' ') {
            answer += word + " ";
            word = "";
            continue;
        }

        word = i + word;
    }
    return answer += word;
}

void reverse_words_in_a_string_iii::Solution::test() {
    assert(reverseWords("Let's take LeetCode contest") == "s'teL ekat edoCteeL tsetnoc");

    cout << "reverseWords completed!" << endl;
}
