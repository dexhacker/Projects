//
// Created by dexhacker on 9/16/22.
//

#include "Solution.h"
#include <vector>
#include <cassert>

string multiply_strings::Solution::multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    vector<string> sums;

    for (int i = num2.size() - 1; i >= 0; i--) {
        int next_number = 0;
        string n = "";

        for (int k = 0; k < num2.size() - 1 - i; k++) n += '0';

        for (int j = num1.size() - 1; j >= 0; j--) {
            int result = next_number;
            int n1 = num2[i] - 48;
            int n2 = num1[j] - 48;
            result += n1 * n2;

            char c = (result % 10) + 48;
            next_number = result / 10;

            n = c + n;
        }

        if (next_number > 0) {
            char last = next_number + 48;
            n = last + n;
        }
        sums.push_back(n);
    }

    string answer = sums[0];
    for (int i = 1; i < sums.size(); i++) {
        string second = sums[i];

        if (answer.size() > second.size()) {
            int length = answer.size() - second.size();
            for (int j = 0; j < length; j++) {
                second = '0' + second;
            }
        }

        if (answer.size() < second.size()) {
            int length = second.size() - answer.size();
            for (int j = 0; j < length; j++) {
                answer = '0' + answer;
            }
        }

        string sub_answer = "";
        int next_number = 0;
        for (int j = answer.size() - 1; j >= 0; j--) {
            int result = next_number;
            int n1 = answer[j] - 48;
            int n2 = second[j] - 48;
            result += n1 + n2;

            char c = (result % 10) + 48;
            next_number = result / 10;
            sub_answer = c + sub_answer;
        }

        if (next_number > 0) {
            char last = next_number + 48;
            sub_answer = last + sub_answer;
        }

        answer = sub_answer;
    }

    return answer;
}

void multiply_strings::Solution::test() {
    assert(multiply("123", "456") == "56088");

    cout << "multiply completed!" << endl;
}
