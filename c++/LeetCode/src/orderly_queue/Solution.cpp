//
// Created by dexhacker on 11/6/22.
//

#include "Solution.h"
#include <cassert>

string orderly_queue::Solution::orderlyQueue(std::string s, int k) {
    if (k == 1) {
        string answer = s;
        for (int i = 0; i < s.size(); i++) {
            s += s[0];
            s.erase(0,1);
            if (s < answer) answer = s;
        }
        return answer;
    } else {
        sort(s.begin(), s.end());
        return s;
    }
}

void orderly_queue::Solution::test() {
    assert(orderlyQueue("cba", 1) == "acb");

    cout << "orderlyQueue completed!" << endl;
}
