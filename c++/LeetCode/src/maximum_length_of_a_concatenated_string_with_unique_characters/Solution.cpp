//
// Created by dexhacker on 10/24/22.
//

#include "Solution.h"
#include <cassert>

void maximum_length_of_a_concatenated_string_with_unique_characters::Solution::bfs(int index, vector<bool> &d, vector<std::string> &arr) {
    for (int i = index; i < arr.size(); i++) {
        string current_s = arr[i];
        vector<bool> current_d(d);
        bool valid = true;
        for (auto c : current_s) {
            if (current_d[c - 'a']) {
                valid = false;
                break;
            }
            current_d[c - 'a'] = true;
        }

        if (valid) {
            bfs(i + 1, current_d, arr);
        }
    }

    int count = 0;
    for (auto b : d) if (b) count++;

    answer = max(answer, count);
}

int maximum_length_of_a_concatenated_string_with_unique_characters::Solution::maxLength(vector<std::string> &arr) {
    vector<bool> d(26, false);
    bfs(0, d, arr);
    return answer;
}

void maximum_length_of_a_concatenated_string_with_unique_characters::Solution::test() {
    vector<string> test {"un", "iq", "ue"};
    assert(maxLength(test) == 4);

    cout << "maxLength completed!" << endl;
}
