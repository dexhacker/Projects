import java.time.LocalTime;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int seconds = scanner.nextInt();
        LocalTime localTime = LocalTime.ofSecondOfDay(seconds);
        System.out.println(localTime);

        scanner.close();
    }
}
