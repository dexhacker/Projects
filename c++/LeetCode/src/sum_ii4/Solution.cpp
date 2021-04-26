//
// Created by dexhacker on 4/22/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>

int sum_ii4::Solution::fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
    unordered_map<int, int> hash_map;
    int answer = 0;
    for (int i : nums1)
        for (int j : nums2)
            hash_map[i + j]++;

    for (int i : nums3)
        for (int j : nums4)
            if (hash_map.count(0 - i - j) > 0)
                answer += hash_map[0 - i - j];

    return answer;
}

void sum_ii4::Solution::test() {
    vector<int> test1_nums1 {1, 2};
    vector<int> test1_nums2 {-2, -1};
    vector<int> test1_nums3 {-1, 2};
    vector<int> test1_nums4 {0, 2};
    assert(fourSumCount(test1_nums1, test1_nums2, test1_nums3, test1_nums4) == 2);

    vector<int> test2_nums1 {0};
    vector<int> test2_nums2 {0};
    vector<int> test2_nums3 {0};
    vector<int> test2_nums4 {0};
    assert(fourSumCount(test2_nums1, test2_nums2, test2_nums3, test2_nums4) == 1);

    vector<int> test3_nums1 {-1,-1};
    vector<int> test3_nums2 {-1,1};
    vector<int> test3_nums3 {-1,1};
    vector<int> test3_nums4 {1,-1};
    assert(fourSumCount(test3_nums1, test3_nums2, test3_nums3, test3_nums4) == 6);

    cout << "fourSumCount completed!" << endl;
}