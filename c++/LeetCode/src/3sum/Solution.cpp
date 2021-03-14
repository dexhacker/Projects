//
// Created by dexhacker on 3/11/21.
//

#include "Solution.h"
#include <cassert>
#include <set>

vector<vector<int>> sum3::Solution::threeSum(vector<int> &nums) {
    if (nums.size() < 3)
        return {};

    sort(nums.begin(), nums.end());

    set<vector<int>> set_answer;

    vector<vector<int>> answer;

    for (int i = 0; i < nums.size(); i++) {
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                set_answer.insert({nums[i], nums[l++], nums[r--]});
            } else if (sum > 0) {
                r--;
            } else if (sum < 0) {
                l++;
            }
        }
    }

    copy(set_answer.begin(), set_answer.end(), back_inserter(answer));

    return answer;
}

void sum3::Solution::test() {
    vector<int> test1 {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> answer1;
    vector<int> sub1_answer1 {-1, -1, 2};
    vector<int> sub2_answer1 {-1, 0, 1};
    answer1.push_back(sub1_answer1);
    answer1.push_back(sub2_answer1);

    assert(threeSum(test1) == answer1);

    vector<int> test2;
    vector<vector<int>> answer2;

    assert(threeSum(test2) == answer2);

    vector<int> test3 {0};
    vector<vector<int>> answer3;

    assert(threeSum(test3) == answer3);

    vector<int> test4 {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    vector<vector<int>> answer4;
    vector<int> sub1_answer4 {-4, 0, 4};
    vector<int> sub2_answer4 {-4, 1, 3};
    vector<int> sub3_answer4 {-3, -1, 4};
    vector<int> sub4_answer4 {-3, 0, 3};
    vector<int> sub5_answer4 {-3, 1, 2};
    vector<int> sub6_answer4 {-2,-1,3};
    vector<int> sub7_answer4 {-2, 0, 2};
    vector<int> sub8_answer4 {-1, -1, 2};
    vector<int> sub9_answer4 {-1, 0, 1};
    answer4.push_back(sub1_answer4);
    answer4.push_back(sub2_answer4);
    answer4.push_back(sub3_answer4);
    answer4.push_back(sub4_answer4);
    answer4.push_back(sub5_answer4);
    answer4.push_back(sub6_answer4);
    answer4.push_back(sub7_answer4);
    answer4.push_back(sub8_answer4);
    answer4.push_back(sub9_answer4);

    assert(threeSum(test4) == answer4);

    cout << "threeSum completed!" << endl;
}
