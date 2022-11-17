//
// Created by dexhacker on 11/17/22.
//

#include "Solution.h"
#include <cassert>

int length_of_last_word::Solution::lengthOfLastWord(std::string s) {
    int answer = 0;
    bool has_space = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            has_space = true;
        } else {
            if (has_space) {
                answer = 0;
                has_space = false;
            }
            answer++;
        }
    }
    return answer;
}

void length_of_last_word::Solution::test() {
    assert(lengthOfLastWord("Hello World") == 5);

    cout << "lengthOfLastWord completed!" << endl;
}
