//
// Created by dexhacker on 12/18/22.
//

#include "Solution.h"
#include <climits>
#include <cassert>

vector<int> daily_temperatures::Solution::dailyTemperatures(vector<int> &temperatures) {
    vector<int> t(71, -1);
    vector<int> answer(temperatures.size(), 0);
    for (int i = temperatures.size() - 1; i >= 0; i--) {
        int min_pos = INT_MAX;
        for (int j = temperatures[i] - 29; j <= 70; j++) if (t[j] != -1 && min_pos > t[j]) min_pos = t[j];
        if (min_pos != INT_MAX) answer[i] = min_pos - i;
        t[temperatures[i] - 30] = i;
    }
    return answer;
}

void daily_temperatures::Solution::test() {
    vector<int> test {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> answer {1, 1, 4, 2, 1, 1, 0, 0};
    auto result = dailyTemperatures(test);
    for (int i = 0; i < answer.size(); i++) assert(answer[i] == result[i]);

    cout << "dailyTemperatures completed!" << endl;
}
