import java.util.Scanner;
import java.time.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int year = scanner.nextInt();
        int days = scanner.nextInt();

        LocalDate date = LocalDate.ofYearDay(year, days);
        int day = date.getDayOfMonth();

        System.out.println(day == 1);

        scanner.close();
    }
}
