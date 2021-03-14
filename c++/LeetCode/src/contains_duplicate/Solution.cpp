//
// Created by dexhacker on 3/10/21.
//

#include "Solution.h"
#include <cassert>
#include <map>

bool contains_duplicate::Solution::containsDuplicate(vector<int>& nums) {
    map<string,int> hashMap;

    for (int num : nums) {
        string stringNum = to_string(num);
        if (hashMap[stringNum] > 0) return true;
        hashMap[stringNum] = 1;
    }
    return false;
}

void contains_duplicate::Solution::test() {
    vector<int> nums1 {1,2,3,1};
    assert(containsDuplicate(nums1));

    vector<int> nums2 {1,2,3,4};
    assert(!containsDuplicate(nums2));

    vector<int> nums3 {1,1,1,3,3,4,3,2,4,2};
    assert(containsDuplicate(nums3));

    cout << "containsDuplicate completed!" << endl;
}