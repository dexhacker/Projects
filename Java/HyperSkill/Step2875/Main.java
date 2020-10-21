import java.time.LocalTime;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LocalTime localTimeFirst = LocalTime.parse(scanner.next());
        LocalTime localTimeSecond = LocalTime.parse(scanner.next());
        int firstSecond = localTimeFirst.toSecondOfDay();
        int secondSecond = localTimeSecond.toSecondOfDay();
        int result;
        if (firstSecond > secondSecond) {
            result = firstSecond - secondSecond;
        } else {
            result = secondSecond - firstSecond;
        }
        System.out.println(result);
        scanner.close();
    }
}
