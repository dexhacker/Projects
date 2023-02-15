//
// Created by dexhacker on 2/15/23.
//

#include "Solution.h"
#include <cassert>

vector<int> add_to_array_form_of_integer::Solution::addToArrayForm(vector<int> &num, int k) {
    string answer;
    vector<int> ans;
    int div = 10;
    int add = 0;
    int n = num.size() - 1;
    while(div / 10 <= k) {
        int number = (k % div) / (div / 10);
        int result = number + add;
        if (n >= 0) result += num[n];
        add = 0;
        if (result > 9) {
            result %= 10;
            add++;
        }

        answer = to_string(result) + answer;

        n--;
        div *= 10;
    }

    while (n >= 0) {
        int result = num[n] + add;
        add = 0;
        if (result > 9) {
            result %= 10;
            add++;
        }
        answer = to_string(result) + answer;

        n--;
    }

    if (add > 0) answer = "1" + answer;

    for (auto i : answer) ans.push_back((int)i - 48);

    return ans;
}

void add_to_array_form_of_integer::Solution::test() {
    vector<int> num {1, 2, 0, 0};
    vector<int> answer {1, 2, 3, 4};
    auto result = addToArrayForm(num, 34);
    for (int i = 0; i < answer.size(); i++) assert(answer[i] == result[i]);

    cout << "addToArrayForm completed!" << endl;
}
