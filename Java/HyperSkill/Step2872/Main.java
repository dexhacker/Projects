import java.util.Scanner;
import java.time.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String timeInString = scanner.next();
        LocalTime localTime = LocalTime.parse(timeInString);
        LocalTime timeWithOutSeconds = localTime.withSecond(0);
        System.out.println(timeWithOutSeconds);

        scanner.close();
    }
}
