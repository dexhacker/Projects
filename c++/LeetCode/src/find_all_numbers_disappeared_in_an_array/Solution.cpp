//
// Created by dexhacker on 3/10/21.
//

#include "Solution.h"
#include <cassert>
#include <map>

vector<int> find_all_numbers_disappeared_in_an_array::Solution::findDisappearedNumbers(vector<int>& nums) {
    map<int,int> hashMap;
    vector<int> answer;

    for (int num : nums) {
        hashMap[num] = num;
    }

    for (int i = 1; i <= nums.size(); i++) {
        if (!hashMap[i]) answer.push_back(i);
    }
    return answer;
}

void find_all_numbers_disappeared_in_an_array::Solution::test() {
    vector<int> nums1 {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> answer1 {5, 6};
    assert(findDisappearedNumbers(nums1) == answer1);

    cout << "findDisappearedNumbers completed!" << endl;
}