import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.LocalTime;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LocalDateTime localDateTime = LocalDateTime.parse(scanner.next());
        long minutes = scanner.nextLong();
        LocalDateTime resultDateTime = localDateTime.plusMinutes(minutes);
        int year = resultDateTime.getYear();
        int daysOfTheYear = resultDateTime.getDayOfYear();

        LocalTime localTime = LocalTime.of(
            resultDateTime.getHour(),
            resultDateTime.getMinute(),
            resultDateTime.getSecond()
        );

        System.out.println(year + " " + daysOfTheYear + " " + localTime);
        scanner.close();
    }
}
