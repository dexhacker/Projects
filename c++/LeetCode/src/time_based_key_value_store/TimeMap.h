//
// Created by dexhacker on 10/6/22.
//

#ifndef LEETCODE_TIME_BASED_KEY_VALUE_STORE_H
#define LEETCODE_TIME_BASED_KEY_VALUE_STORE_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace time_based_key_value_store {
    class TimeMap {
    public:
        TimeMap();
        void set(string key, string value, int timestamp);
        string get(string key, int timestamp);
        static void test();

    private:
        unordered_map<string, vector<pair<int, string>>> m;
    };
}

#endif //LEETCODE_TIME_BASED_KEY_VALUE_STORE_H
