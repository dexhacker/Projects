//
// Created by dexhacker on 3/11/21.
//

#include "Solution.h"
#include <cassert>

vector<int> distribute_candies_to_people::Solution::distributeCandies(int candies, int num_people) {
    vector<int> answer(num_people);
    int current_candies = 0;
    int counter = 0;

    while (candies > 0) {
        current_candies++;
        if (candies - current_candies < 1) {
            current_candies = candies;
            candies = 0;
        }
        candies -= current_candies;
        answer[counter % num_people] += current_candies;
        counter++;
    }

    return answer;
}

void distribute_candies_to_people::Solution::test() {
    vector<int> answer1 {1, 2, 3, 1};
    distributeCandies(7, 4);
    assert(distributeCandies(7, 4) == answer1);

    vector<int> answer2 {5, 2, 3};
    assert(distributeCandies(10, 3) == answer2);

    cout << "distributeCandies completed!" << endl;
}
