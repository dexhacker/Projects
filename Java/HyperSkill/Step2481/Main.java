import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> inputs = new ArrayList<>();
        String input = scanner.next();
        while (!"0".equals(input)) {
            inputs.add(input);
            input = scanner.next();
        }
        String[] items = new String[inputs.size()];
        for (String item : inputs.toArray(items)) {
            try {
                int number = Integer.parseInt(item);
                System.out.println(number * 10);
            } catch (NumberFormatException e) {
                System.out.println("Invalid user input: " + item);
            }
        }
    }
}
