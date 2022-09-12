//
// Created by dexhacker on 9/12/22.
//

#include "Solution.h"
#include <cassert>

int bag_of_tokens::Solution::bagOfTokensScore(vector<int> &tokens, int power) {
    int l = 0;
    int r = tokens.size() - 1;
    int score = 0;
    int answer = 0;

    sort(tokens.begin(), tokens.end());

    while (l <= r) {
        cout << power << endl;
        if (power >= tokens[l]) {
            power -= tokens[l];
            score++;
            answer = max(answer, score);
            l++;
            continue;
        }

        if (score == 0) return answer;

        power += tokens[r];
        score--;
        r--;
    }

    return answer;
}

void bag_of_tokens::Solution::test() {
    vector<int> test1 {100};
    assert(bagOfTokensScore(test1, 50) == 0);

    vector<int> test2 {100, 200};
    assert(bagOfTokensScore(test2, 150) == 1);

    vector<int> test3 {100, 200, 300, 400};
    assert(bagOfTokensScore(test3, 200) == 2);

    cout << "bagOfTokensScore completed!" << endl;
}
