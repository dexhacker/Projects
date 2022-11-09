//
// Created by dexhacker on 11/9/22.
//

#ifndef LEETCODE_ONLINE_STOCK_SPAN_H
#define LEETCODE_ONLINE_STOCK_SPAN_H

#include <iostream>
#include <vector>

using namespace std;

namespace online_stock_span {
    class StockSpanner {
    public:
        int next(int price);
        static void test();

    private:
        vector<pair<int, int>> stocks;
    };
}

#endif //LEETCODE_ONLINE_STOCK_SPAN_H
