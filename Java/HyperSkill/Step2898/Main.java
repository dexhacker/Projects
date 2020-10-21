import java.time.LocalTime;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfStore = scanner.nextInt();
        String[] storeNames = new String[numberOfStore];
        LocalTime[] storeTimes = new LocalTime[numberOfStore];
        for (int i = 0; i < numberOfStore; i++) {
            storeNames[i] = scanner.next();
            storeTimes[i] = LocalTime.parse(scanner.next());
        }

        for (int i = 0; i < numberOfStore; i++) {
            if (storeTimes[i].isAfter(LocalTime.of(20, 0))) {
                System.out.println(storeNames[i]);
            }
        }

        scanner.close();
    }
}
