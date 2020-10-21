package com.arithmeticExpressions;

public class Main {

    public static void main(String[] args) {
        int result = 10 + 3;
        System.out.println(result);

        result = 10 / 3;
        System.out.println(result);

        double result2 = (double)10 / (double)3;
        System.out.println(result2);

        int x = 1;
        x++;
        System.out.println(x);

        ++x;
        System.out.println(x);

        int y = x++;
        System.out.println(x);
        System.out.println(y);

        y = ++x;
        System.out.println(x);
        System.out.println(y);

        x += 2;
        System.out.println(x);
    }
}
