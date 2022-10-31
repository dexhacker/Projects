//
// Created by dexhacker on 10/27/22.
//

#include "Solution.h"
#include <cassert>

int image_overlap::Solution::largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
    int length = img2.size() + img1.size() - 1;
    int width = img2[0].size() + img1[0].size() - 1;

    int answer = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {

            int count = 0;

            for (int k = 0; k < img1.size(); k++) {
                for (int l = 0; l < img1[k].size(); l++) {
                    int img2_l = i - (img1.size() - 1) + k;
                    int img2_w = j - (img1[0].size() - 1) + l;

                    if (img2_l >= 0 && img2_w >= 0 && img2_l < img2.size() && img2_w < img2[0].size()) {
                        if (img2[img2_l][img2_w] == 1 && img1[k][l] == 1) {
                            count++;
                        }
                    }
                }
            }

            answer = max(answer, count);
        }
    }

    return answer;
}

void image_overlap::Solution::test() {
    vector<vector<int>> test1 {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> test2 {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    assert(largestOverlap(test1, test2) == 3);

    cout << "largestOverlap completed!" << endl;
}
