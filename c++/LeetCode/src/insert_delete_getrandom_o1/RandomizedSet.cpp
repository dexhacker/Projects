//
// Created by dexhacker on 3/18/21.
//

#include "RandomizedSet.h"
#include <cassert>

insert_delete_getrandom_o1::RandomizedSet::RandomizedSet() {}

bool insert_delete_getrandom_o1::RandomizedSet::insert(int val) {
    if (hash_map[val]) {
        return false;
    } else {
        hash_map[val] = true;
        return true;
    }
}

bool insert_delete_getrandom_o1::RandomizedSet::remove(int val) {
    if (hash_map[val]) {
        hash_map.erase(val);
        return true;
    } else {
        hash_map.erase(val);
        return false;
    }
}

int insert_delete_getrandom_o1::RandomizedSet::getRandom() {
    int random = rand() % hash_map.size();
    unordered_map<int,bool>::iterator it = hash_map.begin();
    advance(it, random);
    return it->first;
}

void insert_delete_getrandom_o1::RandomizedSet::test() {
    RandomizedSet* randomizedSet = new RandomizedSet();
    assert(randomizedSet->insert(1) == true);
    assert(randomizedSet->remove(2) == false);
    assert(randomizedSet->insert(2) == true);
    assert(randomizedSet->remove(1) == true);
    assert(randomizedSet->insert(2) == false);

    RandomizedSet* randomizedSet2 = new RandomizedSet();
    assert(randomizedSet2->insert(0) == true);
    assert(randomizedSet2->remove(0) == true);
    assert(randomizedSet2->insert(-1) == true);
    assert(randomizedSet2->remove(0) == false);


    cout << "RandomizedSet completed!" << endl;
}
