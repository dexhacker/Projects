//
// Created by Фарид Абдугалыев on 17.01.2022.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

bool word_pattern::Solution::wordPattern(string pattern, string s) {
    string word;
    int index = 0;
    unordered_map<char, string> char_to_str;
    unordered_map<string, char> str_to_char;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (str_to_char.count(word) > 0 && str_to_char[word] != pattern[index]) return false;

            if (char_to_str.count(pattern[index]) > 0) {
                if (char_to_str[pattern[index]] != word) return false;
            } else {
                char_to_str[pattern[index]] = word;
                str_to_char[word] = pattern[index];
            }
            word = "";
            index++;
            if (index >= pattern.size()) return false;
        } else {
            word += s[i];
        }
    }

    if (str_to_char.count(word) > 0 && str_to_char[word] != pattern[index]) return false;

    if (char_to_str.count(pattern[index]) > 0) {
        if (char_to_str[pattern[index]] != word) return false;
    } else {
        char_to_str[pattern[index]] = word;
    }

    return index == pattern.size() - 1;
}

void word_pattern::Solution::test() {
    assert(wordPattern("abba", "dog cat cat dog") == true);
    assert(wordPattern("abba", "dog cat cat fish") == false);
    assert(wordPattern("aaaa", "dog cat cat dog") == false);

    cout << "wordPattern completed!" << endl;
}
