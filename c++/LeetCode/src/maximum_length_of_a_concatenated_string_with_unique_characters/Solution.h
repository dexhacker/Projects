//
// Created by dexhacker on 10/24/22.
//

#ifndef LEETCODE_MAXIMUM_LENGTH_OF_A_CONCATENATED_STRING_WITH_UNIQUE_CHARACTERS_H
#define LEETCODE_MAXIMUM_LENGTH_OF_A_CONCATENATED_STRING_WITH_UNIQUE_CHARACTERS_H

#include <iostream>
#include <vector>

using namespace std;

namespace maximum_length_of_a_concatenated_string_with_unique_characters {
    class Solution {
    public:
        void bfs(int index, vector<bool>& d, vector<string>& arr);
        int maxLength(vector<string>& arr);
        void test();

    private:
        int answer = 0;
    };
}

#endif //LEETCODE_MAXIMUM_LENGTH_OF_A_CONCATENATED_STRING_WITH_UNIQUE_CHARACTERS_H
