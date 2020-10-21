import java.util.Scanner;
import java.time.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int year = scanner.nextInt();
        int months = scanner.nextInt();
        int offset = scanner.nextInt();
        LocalDate date = LocalDate.of(year, months, 1);
        int month = date.getMonthValue() + 1;
        if (month > 12) {
            year += 1;
            month -= 12;
        }
        LocalDate newDate = LocalDate.of(year, month, 1).minusDays(offset);
        System.out.println(newDate);

        scanner.close();
    }
}
