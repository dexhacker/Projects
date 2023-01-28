//
// Created by dexhacker on 1/28/23.
//

#include "SummaryRanges.h"
#include <cassert>

data_stream_as_disjoint_intervals::SummaryRanges::SummaryRanges() {}

void data_stream_as_disjoint_intervals::SummaryRanges::addNum(int value) {
    a[value] = true;
}

vector<vector<int>> data_stream_as_disjoint_intervals::SummaryRanges::getIntervals() {
    vector<vector<int>> answer;
    int start;
    bool used = false;
    for (int i = 0; i < sizeof(a); i++) {
        if (a[i]) {
            if (!used) {
                used = true;
                start = i;
            }
        } else {
            if (used) {
                used = false;
                answer.push_back({start, i - 1});
            }
        }
    }
    if (used) answer.push_back({start, sizeof(a) - 1});
    return answer;
}

void data_stream_as_disjoint_intervals::SummaryRanges::test() {
    auto summaryRanges = new SummaryRanges();
    vector<vector<int>> answer {{1, 3}, {6, 7}};
    summaryRanges->addNum(1);
    summaryRanges->addNum(3);
    summaryRanges->addNum(7);
    summaryRanges->addNum(2);
    summaryRanges->addNum(6);
    auto result = summaryRanges->getIntervals();
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            assert(answer[i][j] == result[i][j]);
        }
    }

    cout << "SummaryRanges completed!" << endl;
}
