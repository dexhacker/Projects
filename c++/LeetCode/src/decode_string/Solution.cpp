//
// Created by Фарид Абдугалыев on 20.12.2021.
//

#include "Solution.h"
#include <cassert>

string decode_string::Solution::decodeString(string s) {
    string result;
    string number_string;

    for (; i < s.size(); i++) {
        if (s[i] > 47 && s[i] < 58) {
            number_string += s[i];
        } else if (s[i] == '[') {
            int number = stoi(number_string);
            i++;
            string temp = decodeString(s);
            for (int j = 0; j < number; j++) {
                result += temp;
            }
            number_string = "";
        } else if (s[i] == ']') {
            return result;
        } else {
            result += s[i];
        }
    }

    return result;
}

void decode_string::Solution::test() {
    assert(decodeString("3[a2[c]]") == "accaccacc");

    cout << "decodeString completed!" << endl;
}
