import java.util.Scanner;

public class Main {

    public static int comb(int n, int k) {
        int sum = 0;
        if (n != k) {
            sum++;
        }
        if (n - 1 > 0) {
            sum += comb(n - 1, k);
        }
        if (k - 1 > 0 && n - 1 > 0) {
            sum += comb(n - 1, k - 1);
        }
        return sum;
    }

    /* Do not change code below */
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(System.in);
        final int n = scanner.nextInt();
        final int k = scanner.nextInt();
        System.out.println(comb(n, k));
    }
}
