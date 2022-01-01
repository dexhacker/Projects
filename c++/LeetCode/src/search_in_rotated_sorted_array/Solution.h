//
// Created by Фарид Абдугалыев on 01.01.2022.
//

#ifndef LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_H

#include <iostream>
#include <vector>

using namespace std;

namespace search_in_rotated_sorted_array {
    class Solution {
    public:
        int find_rotated_index(vector<int>& nums);
        int find_target(vector<int>& nums, int l, int r, int target);
        int search(vector<int>& nums, int target);
        void test();
    };
}

#endif //LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_H
