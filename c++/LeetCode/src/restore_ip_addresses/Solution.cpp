//
// Created by dexhacker on 1/21/23.
//

#include "Solution.h"
#include <cassert>

vector<string> restore_ip_addresses::Solution::restoreIpAddresses(string s) {
    if (s.size() > 12) return {};
    if (s.size() < 4) return {};

    vector<string> answer;

    string ip1;
    for (int i = 0; i < s.size() - 3; i++) {
        ip1 += s[i];
        string ip2;

        if (ip1.size() > 1 && ip1[0] == '0') break;
        if (ip1.size() > 3) break;
        if (stoi(ip1) > 255) break;
        if (s.size() - i - 1 > 9) continue;

        for (int j = i + 1; j < s.size() - 2; j++) {
            ip2 += s[j];
            string ip3;

            if (ip2.size() > 1 && ip2[0] == '0') break;
            if (ip2.size() > 3) break;
            if (stoi(ip2) > 255) break;
            if (s.size() - j - 1 > 6) continue;

            for (int k = j + 1; k < s.size() - 1; k++) {
                ip3 += s[k];
                string ip4;
                bool isFinished = true;

                if (ip3.size() > 1 && ip3[0] == '0') break;
                if (ip3.size() > 3) break;
                if (stoi(ip3) > 255) break;
                if (s.size() - k - 1 > 3) continue;

                for (int l = k + 1; l < s.size(); l++) {
                    ip4 += s[l];

                    if (ip4.size() > 1 && ip4[0] == '0') {
                        isFinished = false;
                        break;
                    }
                    if (ip4.size() > 3) {
                        isFinished = false;
                        break;
                    }
                    if (stoi(ip4) > 255) {
                        isFinished = false;
                        break;
                    }
                }

                if (isFinished) answer.push_back(ip1 + "." + ip2 + "." + ip3 + "." + ip4);
            }
        }
    }
    return answer;
}

void restore_ip_addresses::Solution::test() {
    vector<string> answer {"255.255.11.135", "255.255.111.35"};
    auto result = restoreIpAddresses("25525511135");
    for (int i = 0; i < answer.size(); i++) assert(answer[i] == result[i]);

    cout << "restoreIpAddresses completed!" << endl;
}
