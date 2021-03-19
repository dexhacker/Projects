//
// Created by dexhacker on 3/14/21.
//

#include "Solution.h"
#include <set>

random_pick_with_blacklist::Solution::Solution(int N, vector<int> &blacklist) {
    set<int> set_blacklist(blacklist.begin(), blacklist.end());
    n = N;
    int new_number = N - 1;
    vector<int> mapped_numbers;

    for (int i : set_blacklist)
        hash_map[i] = 0;

    int count = 0 ;
    for (int i : set_blacklist) {
        if (new_number >= 0) {
            while (hash_map.find(new_number) != hash_map.end()) {
                new_number--;
                if (new_number < 0) break;
            }

            if (new_number >= 0) {
                hash_map[i] = new_number;
                mapped_numbers.push_back(new_number);
                new_number--;
            }
        }

        if (new_number < 0) {
            hash_map[i] = mapped_numbers[count];
            count++;
            if (count >= mapped_numbers.size()) count = 0;
        }
    }
}

int random_pick_with_blacklist::Solution::pick() {
    random_device rd;
    gen = mt19937(rd());

    int random_number = dis(gen) % n;
    if (hash_map.find(random_number) != hash_map.end())
        random_number = hash_map[random_number];

    return random_number;
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
//[[3, [2]], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]

//["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
//[[5, [2, 1, 0]], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]
