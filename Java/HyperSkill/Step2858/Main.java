import java.util.Scanner;
import java.time.LocalDateTime;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LocalDateTime localDateTime = LocalDateTime.parse(scanner.next());
        int days = scanner.nextInt();
        int hours = scanner.nextInt();
        LocalDateTime resultDateTime = localDateTime.plusDays(days).minusHours(hours);
        System.out.println(resultDateTime);
        scanner.close();
    }
}
