//
// Created by dexhacker on 3/18/21.
//

#ifndef LEETCODE_INSERT_DELETE_GETRANDOM_O1_H
#define LEETCODE_INSERT_DELETE_GETRANDOM_O1_H

#include <iostream>
#include <unordered_map>

using namespace std;

namespace insert_delete_getrandom_o1 {
    class RandomizedSet {
    public:
        static void test();
        RandomizedSet();
        bool insert(int val);
        bool remove(int val);
        int getRandom();

    private:
        unordered_map<int,bool> hash_map;
    };
}

#endif //LEETCODE_INSERT_DELETE_GETRANDOM_O1_H
