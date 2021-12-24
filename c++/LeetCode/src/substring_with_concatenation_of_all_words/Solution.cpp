//
// Created by Фарид Абдугалыев on 24.12.2021.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

vector<int> substring_with_concatenation_of_all_words::Solution::findSubstring(string s, vector<string> &words) {
    int length = words[0].size();
    unordered_map<string, int> base_map;
    vector<int> answer;

    for (const auto& w : words) base_map[w]++;

    for (int i = 0; i <= (int)s.size() - length * (int)words.size(); i++) {
        string current = s.substr(i, length);

        if (base_map.count(current) > 0) {
            unordered_map<string, int> current_map = base_map;
            current_map[current]--;
            int size = 1;

            for (int j = 1; j < words.size(); j++) {
                string str = s.substr(i + length * j, length);
                if (current_map.count(str) > 0 && current_map[str] > 0) {
                    current_map[str]--;
                    size++;
                } else {
                    break;
                }
            }

            if (size == words.size()) {
                answer.push_back(i);
            }
        }

    }

    return answer;
}

void substring_with_concatenation_of_all_words::Solution::test() {
    vector<string> test1 {"foo", "bar"};
    vector<int> answer1 {0, 9};
    assert(findSubstring("barfoothefoobarman", test1) == answer1);

    vector<string> test2 {"word", "good", "best", "word"};
    vector<int> answer2 {};
    assert(findSubstring("wordgoodgoodgoodbestword", test2) == answer2);

    vector<string> test3 {"bar", "foo", "the"};
    vector<int> answer3 {6, 9, 12};
    assert(findSubstring("barfoofoobarthefoobarman", test3) == answer3);

    cout << "findSubstring completed!" << endl;
}
