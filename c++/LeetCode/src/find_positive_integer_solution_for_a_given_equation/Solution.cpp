//
// Created by dexhacker on 4/22/21.
//

#include "Solution.h"
#include <cassert>

vector<vector<int>> find_positive_integer_solution_for_a_given_equation::Solution::findSolution(CustomFunction &custom_function, int z) {
    vector<vector<int>> solutions;
    for (int x = 1; x <= 1000; x++) {
        int l = 1, r = 1000;
        while (l <= r) {
            int m = (l + r) / 2;
            int result = custom_function.f(x, m);
            if (result < z)
                l = m + 1;
            else if (result > z)
                r = m - 1;
            else {
                solutions.push_back({x, m});
                break;
            }

        }
    }
    return solutions;
}

void find_positive_integer_solution_for_a_given_equation::Solution::test() {
    vector<vector<int>> answer1 {{1, 4}, {2, 3}, {3, 2}, {4, 1}};
    auto *function = new CustomFunction();
    assert(findSolution(*function, 5) == answer1);

    cout << "findSolution completed!" << endl;
}
