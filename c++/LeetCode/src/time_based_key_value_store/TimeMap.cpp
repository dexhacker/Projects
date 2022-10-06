//
// Created by dexhacker on 10/6/22.
//

#include "TimeMap.h"
#include <cassert>

time_based_key_value_store::TimeMap::TimeMap() {

}

void time_based_key_value_store::TimeMap::set(std::string key, std::string value, int timestamp) {
    m[key].push_back({timestamp, value});
}

string time_based_key_value_store::TimeMap::get(std::string key, int timestamp) {
    if (m.count(key) == 0) return "";

    for (int i = m[key].size() - 1; i >= 0; i--) {
        auto p = m[key][i];

        if (p.first <= timestamp) return p.second;
    }

    return "";
}

void time_based_key_value_store::TimeMap::test() {
    auto time_map = new TimeMap();
    time_map->set("foo", "bar", 1);
    assert(time_map->get("foo", 1) == "bar");
    assert(time_map->get("foo", 3) == "bar");
    time_map->set("foo", "bar2", 4);
    assert(time_map->get("foo", 4) == "bar2");
    assert(time_map->get("foo", 5) == "bar2");

    cout << "TimeMap completed!" << endl;
}
