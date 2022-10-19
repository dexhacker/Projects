//
// Created by dexhacker on 10/17/22.
//

#include "Solution.h"
#include <cstring>
#include <cassert>

bool check_if_the_sentence_is_pangram::Solution::checkIfPangram(std::string sentence) {
    if (sentence.size() < 26) return false;

    bool letters[26];
    memset(letters, false, sizeof(letters));
    for (char c : sentence) letters[c - 'a'] = true;
    for (auto b : letters) if (!b) return false;

    return true;
}

void check_if_the_sentence_is_pangram::Solution::test() {
    assert(checkIfPangram("thequickbrownfoxjumpsoverthelazydog") == true);

    cout << "checkIfPangram completed!" << endl;
}
