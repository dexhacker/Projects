//
// Created by dexhacker on 2/7/23.
//

#include "Solution.h"
#include <cassert>

int fruit_into_baskets::Solution::totalFruit(vector<int> &fruits) {
    int answer = 0;
    int tmp_backet = 1;
    int current = fruits[0];
    int backet1 = fruits[0];
    int backet1_count = 1;
    int backet2 = 0;
    int backet2_count = 0;
    for (int i = 1; i < fruits.size(); i++) {
        if (backet1 != fruits[i]) {
            if (backet2 == fruits[i]) {
                backet2_count++;
            } else {
                answer = max(answer, backet1_count + backet2_count);
                backet2_count = tmp_backet;
                backet2 = current;
                backet1 = fruits[i];
                backet1_count = 1;
            }
        } else {
            backet1_count++;
        }
        if (current != fruits[i]) {
            tmp_backet = 1;
            current = fruits[i];
        } else {
            tmp_backet++;
        }
    }
    answer = max(answer, backet1_count + backet2_count);
    return answer;
}

void fruit_into_baskets::Solution::test() {
    vector<int> fruits {1, 2, 1};
    assert(totalFruit(fruits) == 3);

    cout << "totalFruit completed!" << endl;
}
