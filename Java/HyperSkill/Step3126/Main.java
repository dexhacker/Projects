import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        scanner.close();
        int[] listOfArray = new int[number];
        for (int i = 0; i < number; i++) {
            System.out.print(1 + " ");
            listOfArray[i] = 1;
        }
        System.out.println();

        while (listOfArray[0] < number) {
            // int minIndex = number;
            // int minNumber = number;

            // for (int i = 0; i < number; i++) {
            //     if (listOfArray[i] != 0 && listOfArray[i] <= minNumber) {
            //         minNumber = listOfArray[i];
            //         minIndex = i;
            //     }
            // }
            // listOfArray[minIndex]--;

            // int minIndexForAddition = minIndex;
            // minIndex = number;
            // minNumber = number;
            // for (int i = 0; i < minIndexForAddition; i++) {
            //     if (listOfArray[i] < minNumber) {
            //         minNumber = listOfArray[i];
            //         minIndex = i;
            //     }
            // }
            // listOfArray[minIndex]++;
            int minIndex = number;
            int minNumber = number;
            int lastIndex = 0;

            for (int i = 0; i < number; i++) {
                if (listOfArray[i] != 0) {
                    lastIndex = i;
                    if (listOfArray[i] < minNumber) {
                        minNumber = listOfArray[i];
                        minIndex = i;
                    }
                }
            }
            if (lastIndex == minIndex) {
                int subMinIndex = number;
                int subMinNumber = number;
                for (int i = 0; i < number; i++) {
                    if (listOfArray[i] != 0 && listOfArray[i] <= subMinNumber) {
                        minNumber = listOfArray[i];
                        subMinIndex = i;
                    }
                }
                listOfArray[subMinIndex]++;
            } else {
                listOfArray[minIndex]++;
            }

            for (int i = 0; i < number; i++) {
                if (listOfArray[i] != 0 && listOfArray[i] <= minNumber) {
                    minNumber = listOfArray[i];
                    minIndex = i;
                }
            }
            listOfArray[minIndex]--;

            for (int i = 0; i < number; i++) {
                if (listOfArray[i] > 0) {
                    System.out.print(listOfArray[i] + " ");
                }
            }
            System.out.println();
        }
    }
}
