//
// Created by dexhacker on 11/9/22.
//

#include "StockSpanner.h"
#include <cassert>

int online_stock_span::StockSpanner::next(int price) {
    stocks.push_back({price, 1});
    int answer = 0;
    int n = stocks.size() - 1;
    int i = n;

    while (i >= 0) {
        if (stocks[i].first <= price) {
            answer += stocks[i].second;
        } else {
            break;
        }
        i--;
    }

    for (; i < n; i++) if (!stocks.empty()) stocks.pop_back();

    stocks.push_back({price, answer});

    return answer;
}

void online_stock_span::StockSpanner::test() {
    auto stockSpanner = new StockSpanner();
    assert(stockSpanner->next(100) == 1);
    assert(stockSpanner->next(80) == 1);
    assert(stockSpanner->next(60) == 1);
    assert(stockSpanner->next(70) == 2);
    assert(stockSpanner->next(60) == 1);
    assert(stockSpanner->next(75) == 4);
    assert(stockSpanner->next(85) == 6);

    cout << "StockSpanner completed!" << endl;
}
