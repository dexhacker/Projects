//
// Created by dexhacker on 9/18/22.
//

#include "Solution.h"
#include <cassert>

int count_days_spent_together::Solution::countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
    vector<bool> all_days(12*31);

    int arriveAliceMonths = stoi(arriveAlice.substr(0, 2));
    int arriveAliceDays = stoi(arriveAlice.substr(3, 2));
    int arriveAliceInt = get_int(arriveAliceMonths, arriveAliceDays);

    int leaveAliceMonths = stoi(leaveAlice.substr(0, 2));
    int leaveAliceDays = stoi(leaveAlice.substr(3, 2));
    int leaveAliceInt = get_int(leaveAliceMonths, leaveAliceDays);

    int arriveBobMonths = stoi(arriveBob.substr(0, 2));
    int arriveBobDays = stoi(arriveBob.substr(3, 2));
    int arriveBobInt = get_int(arriveBobMonths, arriveBobDays);

    int leaveBobMonths = stoi(leaveBob.substr(0, 2));
    int leaveBobDays = stoi(leaveBob.substr(3, 2));
    int leaveBobInt = get_int(leaveBobMonths, leaveBobDays);

    for (int i = arriveAliceInt; i <= leaveAliceInt; i++) all_days[i] = true;

    int answer = 0;
    for (int i = arriveBobInt; i <= leaveBobInt; i++) if (all_days[i]) answer++;

    return answer;
}

int count_days_spent_together::Solution::get_int(int m, int d) {
    int result = 0;
    for (int i = 0; i < m - 1; i++) {
        result += days[i];
    }
    return result + d;
}

void count_days_spent_together::Solution::test() {
    assert(countDaysTogether("08-15", "08-18", "08-16", "08-19") == 3);
    assert(countDaysTogether("10-01", "10-31", "11-01", "12-31") == 0);

    cout << "countDaysTogether completed!" << endl;
}
