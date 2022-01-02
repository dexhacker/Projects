//
// Created by Фарид Абдугалыев on 02.01.2022.
//

#ifndef LEETCODE_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
#define LEETCODE_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H

#include <iostream>
#include <vector>

using namespace std;

namespace find_first_and_last_position_of_element_in_sorted_array {
    class Solution {
    public:
        void find(vector<int>& nums, int l, int r, int target);
        vector<int> searchRange(vector<int>& nums, int target);
        void test();

    private:
        int start = -1;
        int finish = -1;
    };
}

#endif //LEETCODE_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
