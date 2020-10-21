package com.forEachLoop;

public class Main {

    public static void main(String[] args) {
        String[] fruits = { "Apple", "Mango", "Orange" };

        for (int i = 0; i < fruits.length; i++)
            System.out.println(fruits[i]);

        for (String fruit : fruits)
            System.out.println(fruit);

        for (int i = fruits.length - 1; i >= 0; i--)
            System.out.println(fruits[i]);
    }
}
