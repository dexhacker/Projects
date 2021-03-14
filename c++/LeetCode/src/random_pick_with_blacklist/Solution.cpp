//
// Created by dexhacker on 3/14/21.
//

#include "Solution.h"

random_pick_with_blacklist::Solution::Solution(int N, vector<int> &blacklist) {
    sort(blacklist.begin(), blacklist.end());
    if (blacklist.empty()) {
        vector<int> pair {0, N - 1};
        numbers.push_back(pair);
        return;
    }

    if (blacklist[0] != 0) {
        vector<int> start_pair {0};
        if (blacklist[0] > 1) {
            start_pair.push_back(blacklist[0] - 1);
        } else {
            start_pair.push_back(0);
        }
        numbers.push_back(start_pair);
    }

    for (int i = 1; i < blacklist.size(); i++) {
        if (blacklist[i] - blacklist[i - 1] > 1) {
            vector<int> pair { blacklist[i - 1] + 1,  blacklist[i] - 1};
            numbers.push_back(pair);
        }
    }

    vector<int> finish_pair;
    if (N - 1 - blacklist[blacklist.size() - 1] > 1) {
        finish_pair.push_back(blacklist[blacklist.size() - 1] + 1);
        finish_pair.push_back(N - 1);
        numbers.push_back(finish_pair);
    } else {
         if (N - 1 > blacklist[blacklist.size() - 1]){
             finish_pair.push_back(N - 1);
             finish_pair.push_back(N - 1);
             numbers.push_back(finish_pair);
         }
    }
}

int random_pick_with_blacklist::Solution::pick() {
    vector<int> pair = numbers[rand() % numbers.size()];
    return (rand() % (pair[1] - pair[0] + 1)) + pair[0];
}

void random_pick_with_blacklist::Solution::test() {
    vector<int> vector1;
    Solution* test1 = new Solution(1, vector1);
    test1->pick();
    test1->pick();
    test1->pick();

    vector<int> vector2;
    Solution* test2 = new Solution(2, vector2);
    test2->pick();
    test2->pick();
    test2->pick();

    vector<int> vector3 { 1 };
    Solution* test3 = new Solution(3, vector3);
    test3->pick();
    test3->pick();
    test3->pick();

    vector<int> vector4 { 2 };
    Solution* test4 = new Solution(4, vector4);
    test4->pick();
    test4->pick();
    test4->pick();

    std::cout << "random_pick_with_blacklist completed!" << std::endl;
}

//["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
//[[4, [2, 1]], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]

//["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
//[[3, [0]], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]

//["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
//[[3, [0]], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]

//["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
//[[3, [2]], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]
