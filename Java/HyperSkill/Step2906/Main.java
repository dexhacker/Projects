import java.time.LocalTime;
import java.util.Scanner;

class Main {
    public static boolean compareFirstFormWithSeconds(
        LocalTime firstLocalTimeFrom,
        LocalTime firstLocalTimeTo,
        LocalTime secondLocalTimeFrom,
        LocalTime secondLocalTimeTo) {

        return (firstLocalTimeFrom.isAfter(secondLocalTimeFrom) || firstLocalTimeFrom.equals(secondLocalTimeFrom))
            && (firstLocalTimeFrom.isBefore(secondLocalTimeTo) || firstLocalTimeFrom.equals(secondLocalTimeTo));

    }

    public static boolean compareFirstToWithSeconds(
        LocalTime firstLocalTimeFrom,
        LocalTime firstLocalTimeTo,
        LocalTime secondLocalTimeFrom,
        LocalTime secondLocalTimeTo) {

        return (firstLocalTimeTo.isAfter(secondLocalTimeFrom) || firstLocalTimeTo.equals(secondLocalTimeFrom))
            && (firstLocalTimeTo.isBefore(secondLocalTimeTo) || firstLocalTimeTo.equals(secondLocalTimeTo));

    }

    public static boolean compareSecondFromWithFirsts(
        LocalTime firstLocalTimeFrom,
        LocalTime firstLocalTimeTo,
        LocalTime secondLocalTimeFrom,
        LocalTime secondLocalTimeTo) {

        return (secondLocalTimeFrom.isAfter(firstLocalTimeFrom) || secondLocalTimeFrom.equals(firstLocalTimeFrom))
            && (secondLocalTimeFrom.isBefore(firstLocalTimeTo) || secondLocalTimeFrom.equals(firstLocalTimeTo));

    }

    public static boolean compareSecondToWithFirsts(
        LocalTime firstLocalTimeFrom,
        LocalTime firstLocalTimeTo,
        LocalTime secondLocalTimeFrom,
        LocalTime secondLocalTimeTo) {

        return (secondLocalTimeTo.isAfter(firstLocalTimeFrom) || secondLocalTimeTo.equals(firstLocalTimeFrom))
            && (secondLocalTimeTo.isBefore(firstLocalTimeTo) || secondLocalTimeTo.equals(firstLocalTimeTo));

    }

    public static void main(String[] args) {
        java.util.Arrays.sort(a);
        Scanner scanner = new Scanner(System.in);
        LocalTime firstLocalTimeFrom = LocalTime.parse(scanner.next());
        LocalTime firstLocalTimeTo = LocalTime.parse(scanner.next());
        LocalTime secondLocalTimeFrom = LocalTime.parse(scanner.next());
        LocalTime secondLocalTimeTo = LocalTime.parse(scanner.next());

        boolean result = false;

        result = compareFirstFormWithSeconds(
            firstLocalTimeFrom,
            firstLocalTimeTo,
            secondLocalTimeFrom,
            secondLocalTimeTo
        );
        if (!result) {
            result = compareFirstToWithSeconds(
                firstLocalTimeFrom,
                firstLocalTimeTo,
                secondLocalTimeFrom,
                secondLocalTimeTo
            );
        }
        if (!result) {
            result = compareSecondFromWithFirsts(
                firstLocalTimeFrom,
                firstLocalTimeTo,
                secondLocalTimeFrom,
                secondLocalTimeTo
            );
        }
        if (!result) {
            result = compareSecondToWithFirsts(
                firstLocalTimeFrom,
                firstLocalTimeTo,
                secondLocalTimeFrom,
                secondLocalTimeTo
            );
        }

        System.out.println(result);

        scanner.close();
    }
}
