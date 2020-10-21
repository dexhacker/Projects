package com.abdugalyev;

public class Main {

    public static void main(String[] args) {
//        checkStringToIntegerAtoi();
//        checkPalindromeNumber();
        checkRegularExpressionMatching();
    }

    static void checkRegularExpressionMatching() {
        System.out.println("RegularExpressionMatching:");
        RegularExpressionMatching.Solution problem = new RegularExpressionMatching.Solution();
        compareBoolean(false, problem.isMatch("aa", "a"));
        compareBoolean(true, problem.isMatch("aa", "a*"));
        compareBoolean(true, problem.isMatch("ab", ".*"));
        compareBoolean(true, problem.isMatch("aab", "c*a*b"));
        compareBoolean(false, problem.isMatch("mississippi", "mis*is*p*."));
        System.out.println();
    }

    static void checkPalindromeNumber() {
        System.out.println("PalindromeNumber:");
        PalindromeNumber.Solution problem = new PalindromeNumber.Solution();
        compareBoolean(true, problem.isPalindrome(121));
        compareBoolean(false, problem.isPalindrome(-121));
        compareBoolean(false, problem.isPalindrome(10));
        System.out.println();
    }

    static void checkStringToIntegerAtoi() {
        System.out.println("StringToIntegerAtoi:");
        StringToIntegerAtoi.Solution problem = new StringToIntegerAtoi.Solution();
        compareInt(42, problem.myAtoi("42"));
        compareInt(-42, problem.myAtoi("   -42"));
        compareInt(4193, problem.myAtoi("4193 with words"));
        compareInt(0, problem.myAtoi("words and 987"));
        compareInt(-2147483648, problem.myAtoi("-91283472332"));
        compareInt(-5, problem.myAtoi("-5-"));
        compareInt(-13, problem.myAtoi("-13+8"));
        compareInt(123, problem.myAtoi("123-"));
        System.out.println();
    }

    static void compareInt(int answer, int expect) {
        if (answer == expect) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }

    static void compareBoolean(boolean answer, boolean expect) {
        if (answer == expect) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }
}
