//
// Created by dexhacker on 1/29/23.
//

#include "LFUCache.h"
#include <cassert>

lfu_cache::LFUCache::LFUCache(int capacity) {
    c = capacity;
}

int lfu_cache::LFUCache::get(int key) {
    if (m.count(key) > 0) {
        auto p = h[key];
        auto nc = p.first;
        auto n = p.second;

        if (n->left) {
            n->left->right = n->right;
        } else {
            nc->first = n->right;
            if (n->right) n->right->left = nullptr;
        }
        if (n->right) {
            if (n->left) {
                n->right->left = n->left;
            } else {
                nc->first = n->right;
            }
        } else {
            nc->last = n->left;
        }

        n->right = nullptr;
        n->left = nullptr;

        if (nc->down) {
            if (nc->down->val == nc->val + 1) {
                nc->down->last->right = n;
                n->left = nc->down->last;
                nc->down->last = n;
            } else {
                auto new_down = new LFUCacheNodeCount();
                new_down->up = nc;
                new_down->val = nc->val + 1;
                new_down->first = n;
                new_down->last = n;
                new_down->down = nc->down;
                nc->down->up = new_down;
                nc->down = new_down;
            }
        } else {
            nc->down = new LFUCacheNodeCount();
            nc->down->up = nc;
            nc->down->val = nc->val + 1;
            nc->down->first = n;
            nc->down->last = n;
        }
        h[key].first = nc->down;
        if (nc->first == nullptr && nc->last == nullptr) {
            if (nc->up) {
                nc->up->down = nc->down;
                nc->down->up = nc->up;
            } else {
                head = nc->down;
                head->up = nullptr;
            }
        }

        return m[key];
    }

    return -1;
}

void lfu_cache::LFUCache::put(int key, int value) {
    if (m.count(key) > 0) {
        m[key] = value;
        get(key);
        return;
    }

    if (c == 0) {
        if (head == nullptr) return;

        auto n = head->first;
        if (head->first == head->last) {
            head = head->down;
        } else {
            head->first = head->first->right;
            head->first->left = nullptr;
        }
        m.erase(n->val);
        h.erase(n->val);
    }

    if (c != 0) c -= 1;

    m[key] = value;
    if (head) {
        if (head->val == 1) {
            head->last->right = new LFUCacheNode();
            head->last->right->val = key;
            head->last->right->left = head->last;
            head->last = head->last->right;

            h[key] = {head, head->last};
        } else {
            auto new_head = new LFUCacheNodeCount();
            new_head->val = 1;
            new_head->first = new LFUCacheNode();
            new_head->first->val = key;
            new_head->last = new_head->first;
            h[key] = {new_head, new_head->first};

            new_head->down = head;
            head->up = new_head;
            head = new_head;
        }
    } else {
        head = new LFUCacheNodeCount();
        head->val = 1;
        head->first = new LFUCacheNode();
        head->first->val = key;
        head->last = head->first;
        h[key] = {head, head->first};
    }
}

void lfu_cache::LFUCache::test() {
    auto lfu = new LFUCache(2);
    lfu->put(1, 1);
    lfu->put(2, 2);
    assert(lfu->get(1) == 1);
    lfu->put(3, 3);
    assert(lfu->get(2) == -1);
    assert(lfu->get(3) == 3);
    lfu->put(4, 4);
    assert(lfu->get(1) == -1);
    assert(lfu->get(3) == 3);
    assert(lfu->get(4) == 4);

    cout << "LFUCache completed!" << endl;
}
