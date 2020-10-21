import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger number = new BigInteger(scanner.next());

        BigInteger counter = BigInteger.ONE;
        BigInteger factorial = BigInteger.ONE;

        while (number.compareTo(factorial) == 1) {
            counter = counter.add(BigInteger.ONE);
            factorial = factorial.multiply(counter);
        }

        System.out.println(counter);

        scanner.close();
    }
}
