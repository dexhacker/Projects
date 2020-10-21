package AddTwoNumbers;

import java.util.Objects;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode firstNode = l1;
        ListNode secondNode = l2;
        ListNode firstResultNode = null;
        ListNode resultNode = null;
        boolean tens = false;

        while (true) {
            int result = firstNode.val + secondNode.val;

            if (tens) {
                result++;
            }

            tens = result > 9;

            int number = result % 10;

            if (resultNode == null) {
                resultNode = new ListNode(number);
                firstResultNode = resultNode;
            } else {
                resultNode.next = new ListNode(number);
                resultNode = resultNode.next;
            }

            if (firstNode.next == null && secondNode.next == null) {
                if (tens) {
                    resultNode.next = new ListNode(1);
                }
                return firstResultNode;
            }

            firstNode = Objects.requireNonNullElseGet(firstNode.next, () -> new ListNode(0));

            secondNode = Objects.requireNonNullElseGet(secondNode.next, () -> new ListNode(0));
        }
    }
}
