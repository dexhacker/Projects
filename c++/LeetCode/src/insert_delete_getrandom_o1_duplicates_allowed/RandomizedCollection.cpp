//
// Created by dexhacker on 3/28/21.
//

#include "RandomizedCollection.h"
#include <cassert>

insert_delete_getrandom_o1_duplicates_allowed::RandomizedCollection::RandomizedCollection() {

}

bool insert_delete_getrandom_o1_duplicates_allowed::RandomizedCollection::insert(int val) {
    bool answer = map_of_numbers[val].empty();
    numbers.push_back(val);
    map_of_numbers[val][numbers.size() -1] = true;
    return answer;
}

bool insert_delete_getrandom_o1_duplicates_allowed::RandomizedCollection::remove(int val) {
    bool answer = map_of_numbers[val].empty();
    if (answer) return false;

    int index = map_of_numbers[val].begin()->first;
    map_of_numbers[val].erase(index);
    int temp_index = numbers.size() - 1;
    if (index != temp_index) {
        int temp = numbers[temp_index];
        numbers[temp_index] = numbers[index];
        numbers[index] = temp;
        numbers.pop_back();
        map_of_numbers[temp].erase(temp_index);
        map_of_numbers[temp][index] = true;
    } else {
        numbers.pop_back();
    }
    return true;
}

int insert_delete_getrandom_o1_duplicates_allowed::RandomizedCollection::getRandom() {
    int random_index = rand() % numbers.size();
    return numbers[random_index];
}

void insert_delete_getrandom_o1_duplicates_allowed::RandomizedCollection::test() {
    auto *randomizedCollection1 = new RandomizedCollection();
    assert(randomizedCollection1->insert(1) == true);
    assert(randomizedCollection1->insert(1) == false);
    assert(randomizedCollection1->insert(2) == true);
    randomizedCollection1->getRandom();
    assert(randomizedCollection1->remove(1) == true);
    randomizedCollection1->getRandom();

    auto *randomizedCollection2 = new RandomizedCollection();
    assert(randomizedCollection2->insert(0) == true);
    assert(randomizedCollection2->remove(0) == true);
    assert(randomizedCollection2->insert(-1) == true);
    assert(randomizedCollection2->remove(0) == false);
    randomizedCollection2->getRandom();

    std::cout << "RandomizedCollection completed!" << std::endl;
}
