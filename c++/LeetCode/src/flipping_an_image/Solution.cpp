//
// Created by dexhacker on 3/25/21.
//

#include "Solution.h"
#include <cassert>

vector<vector<int>> flipping_an_image::Solution::flipAndInvertImage(vector<vector<int>> &image) {
    for (int i = 0; i < image.size(); i++) {
        int l = 0;
        int r = image[i].size() - 1;
        while (l <= r) {
            if (l == r) {
                image[i][l] = (image[i][l] + 1) % 2;
                l++; r--;
                continue;
            }

            int temp = image[i][l];
            image[i][l] = image[i][r];
            image[i][r] = temp;
            image[i][l] = (image[i][l] + 1) % 2;
            image[i][r] = (image[i][r] + 1) % 2;

            l++; r--;
        }
    }
    return image;
}

void flipping_an_image::Solution::test() {
    vector<vector<int>> test1 = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    vector<vector<int>> answer1 = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    assert(flipAndInvertImage(test1) == answer1);

    vector<vector<int>> test2 = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
    vector<vector<int>> answer2 = {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}};
    assert(flipAndInvertImage(test2) == answer2);

    cout << "flipAndInvertImage completed!" << endl;
}
