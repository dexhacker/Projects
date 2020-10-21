package com.breakAndContinue;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = "";
        while (true) {
            System.out.println("Input: ");
            input = scanner.nextLine().toLowerCase();
            if (input.equals("pass"))
                continue;
            if (input.equals("exit"))
                break;
            System.out.println(input);
        }
    }
}
