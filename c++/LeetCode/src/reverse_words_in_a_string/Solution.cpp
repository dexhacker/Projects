//
// Created by dexhacker on 11/13/22.
//

#include "Solution.h"
#include <cassert>

string reverse_words_in_a_string::Solution::reverseWords(std::string s) {
    string answer;
    string word;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            if (word != "") {
                if (answer == "") {
                    answer += word;
                } else {
                    answer += " " + word;
                }
                word = "";
            }
        } else {
            word = s[i] + word;
        }
    }
    if (word != "") {
        if (answer == "") {
            answer += word;
        } else {
            answer += " " + word;
        }
    }
    return answer;
}

void reverse_words_in_a_string::Solution::test() {
    assert(reverseWords("the sky is blue") == "blue is sky the");

    cout << "reverseWords completed!" << endl;
}
