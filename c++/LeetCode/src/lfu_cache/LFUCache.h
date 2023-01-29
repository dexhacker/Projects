//
// Created by dexhacker on 1/29/23.
//

#ifndef LEETCODE_LFU_CACHE_H
#define LEETCODE_LFU_CACHE_H

#include <iostream>
#include <unordered_map>

using namespace std;

struct LFUCacheNode {
    int val;
    LFUCacheNode *left;
    LFUCacheNode *right;
};

struct LFUCacheNodeCount {
    int val;
    LFUCacheNodeCount *up;
    LFUCacheNodeCount *down;
    LFUCacheNode *first;
    LFUCacheNode *last;
};

namespace lfu_cache {
    class LFUCache {
    private:
        int c;
        unordered_map<int, int> m;
        LFUCacheNodeCount *head = nullptr;
        unordered_map<int, pair<LFUCacheNodeCount*, LFUCacheNode*>> h;

    public:
        LFUCache(int capacity);
        int get(int key);
        void put(int key, int value);
        static void test();
    };
}

#endif //LEETCODE_LFU_CACHE_H
