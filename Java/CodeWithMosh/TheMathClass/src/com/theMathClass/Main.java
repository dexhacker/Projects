package com.theMathClass;

public class Main {

    public static void main(String[] args) {
        int result = Math.round(1.1F);
        System.out.println(result);

        int result2 = (int)Math.ceil(1.1F);
        System.out.println(result2);

        int result3 = (int)Math.floor(1.1F);
        System.out.println(result3);

        int result4 = Math.max(1, 2);
        System.out.println(result4);

        int result5 = (int)(Math.random() * 100);
        System.out.println(result5);
    }
}
