//
// Created by dexhacker on 5/20/21.
//

#include "Solution.h"
#include <cassert>

string remove_k_digits::Solution::removeKdigits(string num, int k) {
    vector<char> stack;
    if(k == num.size()) return "0";
    int index = 0;
    while(index < num.size()){
        int n = stack.size();
        while(k && n && stack[n - 1] > num.at(index)){
            k--;
            stack.pop_back();
            n = stack.size();
        }
        stack.push_back(num.at(index++));
    }
    while(k-- > 0){
        stack.pop_back();
    }
    int n = stack.size();
    string small;
    while(!stack.empty()){
        small =  stack[n - 1] + small;
        n--;
        stack.pop_back();
    }
    while(small.size() > 1 && small[0] == '0'){
        small = small.substr(1);
    }
    return small;
}

void remove_k_digits::Solution::test() {
    assert(removeKdigits("1432219", 3) == "1219");
    assert(removeKdigits("10200", 1) == "200");
    assert(removeKdigits("10", 2) == "0");
    assert(removeKdigits("9", 1) == "0");
    assert(removeKdigits("120", 2) == "0");
    assert(removeKdigits("1234567890", 9) == "0");
    assert(removeKdigits("112", 1) == "11");

    cout << "removeKdigits completed!" << endl;
}
