//
// Created by dexhacker on 4/15/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>

vector<int> intersection_of_two_arrays_ii::Solution::intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> hash_map;
    vector<int> answer;
    for (int i : nums1)
        hash_map[i]++;

    for (int i : nums2) {
        if (hash_map[i] > 0) {
            answer.push_back(i);
            hash_map[i]--;
        }
    }

    return answer;
}

void intersection_of_two_arrays_ii::Solution::test() {
    vector<int> test1_vector1 {1, 2, 2, 1};
    vector<int> test1_vector2 {2, 2};
    vector<int> answer1 {2, 2};
    assert(intersect(test1_vector1, test1_vector2) == answer1);

    vector<int> test2_vector1 {4, 9, 5};
    vector<int> test2_vector2 {9, 4, 9, 8, 4};
    vector<int> answer2 {9, 4};
    assert(intersect(test2_vector1, test2_vector2) == answer2);

    cout << "intersect completed!" << endl;
}
