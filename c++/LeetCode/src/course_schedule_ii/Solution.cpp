//
// Created by Фарид Абдугалыев on 23.12.2021.
//

#include "Solution.h"
#include <cassert>

vector<int> course_schedule_ii::Solution::findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> courses(numCourses);
    vector<bool> used(numCourses);
    vector<int> answer;

    for (auto course : prerequisites) {
        courses[course[0]].push_back(course[1]);
    }

    while (answer.size() < numCourses) {
        bool changed = false;

        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) {
                bool can_use = true;
                for (auto course : courses[i]) {
                    if (!used[course]) {
                        can_use = false;
                        break;
                    }
                }

                if (can_use) {
                    used[i] = true;
                    answer.push_back(i);
                    changed = true;
                }
            }
        }

        if (!changed) return {};
    }

    return answer;
}

void course_schedule_ii::Solution::test() {
    vector<vector<int>> test1 {{1,0}};
    vector<int> answer1 {0, 1};
    assert(findOrder(2, test1) == answer1);

    vector<vector<int>> test2 {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> answer2 {0, 1, 2, 3};
    assert(findOrder(4, test2) == answer2);

    vector<vector<int>> test3 {};
    vector<int> answer3 {0};
    assert(findOrder(1, test3) == answer3);

    cout << "findOrder completed!" << endl;
}
