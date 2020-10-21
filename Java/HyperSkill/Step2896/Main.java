import java.time.LocalDate;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LocalDate localDate = LocalDate.parse(scanner.next());
        int days = scanner.nextInt();
        int year = localDate.getYear();
        LocalDate resultLocalDate = localDate.plusDays(days);
        System.out.println(year < resultLocalDate.getYear());
        scanner.close();
    }
}
