//
// Created by Фарид Абдугалыев on 20.12.2021.
//

#include "Solution.h"
#include <cassert>

vector<vector<int>> minimum_absolute_difference::Solution::minimumAbsDifference(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    vector<vector<int>> answer;

    int difference = arr[1] - arr[0];
    answer.push_back({arr[0], arr[1]});

    for (int i = 2; i < arr.size(); i++) {
        if ((arr[i] - arr[i - 1]) == difference) {
            answer.push_back({arr[i - 1], arr[i]});
        }

        if ((arr[i] - arr[i - 1]) < difference) {
            difference = arr[i] - arr[i - 1];
            answer.clear();
            answer.push_back({arr[i - 1], arr[i]});
        }
    }

    return answer;
}

void minimum_absolute_difference::Solution::test() {
    vector<int> test1 {4, 2, 1, 3};
    vector<vector<int>> answer1 {{1, 2}, {2, 3}, {3, 4}};
    assert(minimumAbsDifference(test1) == answer1);

    vector<int> test2 {1, 3, 6, 10, 15};
    vector<vector<int>> answer2 {{1, 3}};
    assert(minimumAbsDifference(test2) == answer2);

    vector<int> test3 {3, 8, -10, 23, 19, -4, -14, 27};
    vector<vector<int>> answer3 {{-14, -10}, {19, 23}, {23, 27}};
    assert(minimumAbsDifference(test3) == answer3);

    cout << "minimumAbsDifference completed!" << endl;
}
