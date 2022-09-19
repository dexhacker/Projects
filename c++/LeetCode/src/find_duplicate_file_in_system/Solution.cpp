//
// Created by dexhacker on 9/19/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

vector<vector<string>> find_duplicate_file_in_system::Solution::findDuplicate(vector<std::string> &paths) {
    unordered_map<string, vector<string>> mp;

    for (auto i : paths) {
        string path;
        int j = 0;
        while (i[j] != ' ') {
            path += i[j];
            j++;
        }

        j++;

        string file_name;
        string content;
        bool has_content = false;
        while (j < i.size()) {

            if (i[j] == ' ') {
                mp[content].push_back(path + "/" + file_name);

                file_name = "";
                content = "";
            } else {
                if (i[j] == ')') has_content = false;

                if (has_content) content += i[j];

                if (i[j] == '(') has_content = true;

                if (!has_content && i[j] != ')') file_name += i[j];
            }

            j++;
        }


        mp[content].push_back(path + "/" + file_name);
    }

    vector<vector<string>> answer;

    for (const auto& kv : mp) if (kv.second.size() > 1) answer.push_back(kv.second);

    return answer;
}

void find_duplicate_file_in_system::Solution::test() {
    vector<string> test1 {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    vector<vector<string>> answer1 {
            {"root/a/2.txt", "root/c/d/4.txt","root/4.txt"},
            {"root/a/1.txt", "root/c/3.txt"}
    };
    assert(findDuplicate(test1) == answer1);

    cout << "findDuplicate completed!" << endl;
}
