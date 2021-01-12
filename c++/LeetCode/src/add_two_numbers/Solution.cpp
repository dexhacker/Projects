//
// Created by dexhacker on 1/12/21.
//

#include "Solution.h"
#include <iostream>
#include <cassert>

using namespace std;

add_two_numbers::ListNode * add_two_numbers::Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    int sum = 0;
    ListNode * l3 = nullptr;
    ListNode ** node = &l3;
    while (l1 != nullptr || l2 != nullptr || sum > 0) {
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        (*node) = new ListNode(sum % 10);
        sum /= 10;
        node = &((*node)->next);
    }
    return l3;
}

void add_two_numbers::Solution::test() {
//    TEST 1
    ListNode * firstNumber;
    firstNumber = new ListNode(2);
    firstNumber = new ListNode(4, firstNumber);
    firstNumber = new ListNode(3, firstNumber);

    ListNode * secondNumber;
    secondNumber = new ListNode(5);
    secondNumber = new ListNode(6, secondNumber);
    secondNumber = new ListNode(4, secondNumber);

    ListNode * result;
    result = new ListNode(8);
    result = new ListNode(0, result);
    result = new ListNode(7, result);

    ListNode * plainResult;
    plainResult = addTwoNumbers(firstNumber, secondNumber);

    while (true) {
        assert(plainResult->val == result->val);
        if (plainResult->next) {
            plainResult = plainResult->next;
            result = result->next;
        } else {
            break;
        }
    }

//    TEST 2

    firstNumber = new ListNode(0);
    secondNumber = new ListNode(0);
    result = new ListNode(0);

    plainResult = addTwoNumbers(firstNumber, secondNumber);

    while (true) {
        assert(plainResult->val == result->val);
        if (plainResult->next) {
            plainResult = plainResult->next;
            result = result->next;
        } else {
            break;
        }
    }

//    TEST 3
    firstNumber = new ListNode(9);
    firstNumber = new ListNode(9, firstNumber);
    firstNumber = new ListNode(9, firstNumber);
    firstNumber = new ListNode(9, firstNumber);
    firstNumber = new ListNode(9, firstNumber);
    firstNumber = new ListNode(9, firstNumber);
    firstNumber = new ListNode(9, firstNumber);

    secondNumber = new ListNode(9);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(9, secondNumber);

    result = new ListNode(1);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(9, result);
    result = new ListNode(9, result);
    result = new ListNode(9, result);
    result = new ListNode(8, result);

    plainResult = addTwoNumbers(firstNumber, secondNumber);

    while (true) {
        assert(plainResult->val == result->val);
        if (result->next) {
            plainResult = plainResult->next;
            result = result->next;
        } else {
            break;
        }
    }

//    TEST 4
    firstNumber = new ListNode(9);

    secondNumber = new ListNode(9);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(9, secondNumber);
    secondNumber = new ListNode(1, secondNumber);

    result = new ListNode(1);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);

    plainResult = addTwoNumbers(firstNumber, secondNumber);

    while (true) {
        assert(plainResult->val == result->val);
        if (result->next) {
            plainResult = plainResult->next;
            result = result->next;
        } else {
            break;
        }
    }

//    TEST 5
    firstNumber = new ListNode(1);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(0, firstNumber);
    firstNumber = new ListNode(1, firstNumber);

    secondNumber = new ListNode(5);
    secondNumber = new ListNode(6, secondNumber);
    secondNumber = new ListNode(4, secondNumber);

    result = new ListNode(1);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(0, result);
    result = new ListNode(5, result);
    result = new ListNode(6, result);
    result = new ListNode(5, result);

    plainResult = addTwoNumbers(firstNumber, secondNumber);

    while (true) {
        assert(plainResult->val == result->val);
        if (result->next) {
            plainResult = plainResult->next;
            result = result->next;
        } else {
            break;
        }
    }

    cout << "addTwoNumbers completed!" << endl;
}
