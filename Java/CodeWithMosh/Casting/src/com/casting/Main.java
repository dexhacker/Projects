package com.casting;

public class Main {

    public static void main(String[] args) {
        short x = 1;
        int y = x + 2;
        System.out.println(y);

        double x2 = 1.1;
        double y2 =  x2 + 2;
        System.out.println(y2);

        double x3 = 1.1;
        int y3 = (int)x3 + 2;
        System.out.println(y3);

        String x4 = "1";
        int y4 = Integer.parseInt(x4) + 2;
        System.out.println(y4);

        String x5 = "1.1";
        double y5 = Double.parseDouble(x5) + 2;
        System.out.println(y5);
    }
}
