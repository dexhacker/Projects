package com.ifStatements;

public class Main {

    public static void main(String[] args) {
        int temp = 32;
        if (temp > 30) {
            System.out.println("It's hot day");
            System.out.println("Drink water");
        } else if (temp > 20) {
            System.out.println("Beautiful day");
        } else {
            System.out.println("Cold day");
        }
    }
}
