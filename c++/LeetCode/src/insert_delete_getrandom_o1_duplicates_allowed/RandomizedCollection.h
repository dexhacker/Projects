//
// Created by dexhacker on 3/28/21.
//

#ifndef LEETCODE_INSERT_DELETE_GETRANDOM_O1_DUPLICATES_ALLOWED_H
#define LEETCODE_INSERT_DELETE_GETRANDOM_O1_DUPLICATES_ALLOWED_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace insert_delete_getrandom_o1_duplicates_allowed {
    class RandomizedCollection {
    public:
        static void test();

        RandomizedCollection();

        bool insert(int val);

        bool remove(int val);

        int getRandom();

    private:
        unordered_map<int,unordered_map<int, bool>> map_of_numbers;
        vector<int> numbers;
    };
}

#endif //LEETCODE_INSERT_DELETE_GETRANDOM_O1_DUPLICATES_ALLOWED_H
