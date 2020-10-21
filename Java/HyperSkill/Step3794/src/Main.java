import java.util.Scanner;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String firstLine = scanner.nextLine();
        int target = scanner.nextInt();

        scanner = new Scanner(firstLine);

        int minRange = Integer.MAX_VALUE;
        int maxRange = Integer.MAX_VALUE;
        ArrayList<Integer> minNumbers = new ArrayList<>();
        ArrayList<Integer> maxNumbers = new ArrayList<>();
        ArrayList<Integer> numbers = new ArrayList<>();

        while (scanner.hasNextInt()) {
            int number = scanner.nextInt();
            if (number > target && numbers.size() == 0) {
                int result = number - target;
                if (result < maxRange) {
                    maxNumbers.clear();
                    maxNumbers.add(number);
                    maxRange = result;
                } else if (result == maxRange) {
                    maxNumbers.add(number);
                }
            }
            if (number < target && numbers.size() == 0) {
                int result = target - number;
                if (result < minRange) {
                    minNumbers.clear();
                    minNumbers.add(number);
                    minRange = result;
                } else if (result == minRange) {
                    minNumbers.add(number);
                }
            }
            if (number == target) {
                numbers.add(number);
                minNumbers.clear();
                maxNumbers.clear();
            }
        }

        for (int number : minNumbers) {
            System.out.print(number + " ");
        }
        for (int number : numbers) {
            System.out.print(number + " ");
        }
        for (int number : maxNumbers) {
            System.out.print(number + " ");
        }
    }
}
