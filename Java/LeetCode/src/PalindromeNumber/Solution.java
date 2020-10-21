package PalindromeNumber;

public class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false;

        int number = x;
        int currentNumber = 0;
        while (number > 0) {
            int digit = number % 10;
            currentNumber = currentNumber * 10 + digit;
            number = number / 10;
        }
        return currentNumber == x;
    }
}
